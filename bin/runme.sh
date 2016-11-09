#!/bin/bash

function getvol() { echo $(grep ' /data ' /proc/self/mountinfo | cut -f 4 -d" "); }
_vol=$(getvol)

if [ ! "${_vol}" ]; then 
    echo -e "ERROR: you need run Docker with the -v parameter, try:"
    echo "    docker run --rm -v /tmp:/data aquaron/tmk-infinity example"
    exit 1
fi

HELP=`cat <<EOT
Usage: docker run --rm -v <local-dir>:/data aquaron/tmk-infinity <tag> [<keyboard>] [<target>]

Example: docker run --rm -v $_vol:/data aquaron/tmk-infinity example

 local-dir  - directory on the host system to map to container
 tag        - tag name to be used, part of the keymap_<tag>.c file
 keyboard   - optional keyboard profile like hhkb (default: infinity)
 target     - optional target, they are specific to keyboard (default: led)

Resulting files will be published in the <local-dir> (ex: check $_vol) directory.
EOT`

if [[ $# -lt 1 ]] || [[ ! "${_vol}" ]]; then echo "$HELP"; exit 1; fi

_tag=$1
_dir=$2
_target=$3
if [ ! "$_dir" ]; then _dir="infinity"; fi
_file=keymap_${_tag}.c
_datadir=/data
_datafile=${_datadir}/${_file}
_exdir=examples
_exfile="../${_exdir}/${_dir}.c"

if [ ! -d "${_dir}" ]; then
    echo "ERROR: keyboard ${_dir} is invalid"
    exit 1
fi

cd $_dir

if [ "$_tag" = "example" ]; then 
    ### look for file in examples dir and copy over to build dir and /data for user
    if [ -s "${_exfile}" ]; then
        cp ${_exfile} ${_datafile}
        cp ${_exfile} ${_file}
    else
        echo -e "ERROR: example file $_file does not exist for keyboard $_dir sorry!"
        exit 1
    fi
else
    if [ -s "${_datafile}" ]; then
        cp ${_datafile} .
    else
        echo -e "ERROR: ${_datafile} not found\nCheck ${_vol}/$_file to see if it's there"
        exit 1
    fi
fi 

if [ ! -s "${_file}" ]; then
    echo "ERROR: ${_file} not found. Abort!"
    exit 1
fi

case "${_dir}" in
    infinity)
        if [ ! "$_target" ]; then _target="led"; fi
        make -s -f Makefile.${_target} -e KEYMAP=${_tag}
        _binfile="${_dir}_${_tag}.bin"
        cp build/infinity.bin ${_datadir}/${_binfile}
        ;;

    hhkb)
        if [ ! "$_target" ]; then _target="rn42"; fi
        _binfile="${_dir}_${_tag}.hex"
        make -s -f Makefile.${_target} -e KEYMAP=${_tag}
        cp hhkb_${_target}.hex ${_datadir}/${_binfile}
        ;;

    *)
        echo "Keyboard $_dir not supported"
        exit 1;
        ;;
esac

echo -e "\nDONE: file at ${_vol}/${_binfile} is ready!"

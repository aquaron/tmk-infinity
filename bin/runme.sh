#!/bin/bash

if [ ! "$1" ]; then
	echo "keymap name is required"
	exit 1
fi

_file=keymap_$1.c

if [ "$1" != "custom" ]; then 
	if [ -s "/data/$_file" ]; then
		cp /data/$_file .
	else
		echo "/data/$_file not found"
		exit 1
	fi
else
	cp $_file /data
fi 

if [ -s "$_file" ]; then
	make -f Makefile.led -e KEYMAP=$1
	cp build/infinity.bin /data
	exit 0
fi

echo "$_file not found"

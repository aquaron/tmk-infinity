# tmk-infinity

Uses TMK to build the data file to flash Input Club's Infinity 60%.
Optionally, you can build hex files for HHKB.

### Syntax

    docker run --rm -v <local-dir>:/data aquaron/tmk-infinity <tag> [<keyboard>] [<target>]

`<tag>` is the name of the keymap file that contains the mapping to customize your keyboard layout.
See https://github.com/tmk/tmk_keyboard/tree/master/keyboard/infinity 
for detailed information on how to customize the layout.
Create a `keymap_mylayout.c` file and put it in `<local-dir>` and issue this command to run:

    docker run --rm -v /tmp:/data aquaron/tmk-infinity mylayout


## Examples

### Build Example Keyboard

To check out a custom layout that uses VI-style cursor using dual-role semi-colon key as a layer switch run
the command below and check out `keymap_example.c` in `/tmp`.

    docker run --rm -v /tmp:/data aquaron/tmk-infinity example

### Build HHKB Hex File

Building HHKB's hex file to flash HHKB Bluetooth version:

    docker run --rm -v /tmp:/data aquaron/tmk-infinity example hhkb rn42


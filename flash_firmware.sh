# cd keyboards/tractyl/keymaps/jonboh/
# qmk json2c jonboh.json -o jonboh.c
# cd -
qmk compile -kb tractyl -km default -j 8
dfu-programmer atmega32u4 erase --force
dfu-programmer atmega32u4 flash tractyl_default.hex
dfu-programmer atmega32u4 reset

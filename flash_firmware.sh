cd keyboards/handwired/dactyl_manuform/4x6/keymaps/jonboh/
qmk json2c jonboh.json -o jonboh.c
cd ../../../../../../
qmk compile -kb handwired/dactyl_manuform/4x6 -km jonboh -j 8
dfu-programmer atmega32u4 erase --force
dfu-programmer atmega32u4 flash handwired_dactyl_manuform_4x6_jonboh.hex
dfu-programmer atmega32u4 reset

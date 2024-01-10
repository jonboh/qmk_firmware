# cd keyboards/tractyl/keymaps/jonboh/
# qmk json2c jonboh.json -o jonboh.c
# cd -
# qmk flash -kb vertyl -km default -j 8 -e CONVERT_TO=promicro_rp2040
# qmk flash -kb handwired/dactyl_manuform/4x6 -km jonboh -j 8
# dfu-programmer atmega32u4 erase --force
# dfu-programmer atmega32u4 flash vertyl_default.hex
# dfu-programmer atmega32u4 reset
qmk compile -kb ulp_dactyl -km default -j 8 -e CONVERT_TO=promicro_rp2040
sleep 2
cp ulp_dactyl_default_promicro_rp2040.uf2 /run/media/jonboh/RPI-RP2/


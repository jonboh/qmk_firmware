cd keyboards/handwired/dactyl_manuform/4x6/keymaps/jonboh/
qmk json2c jonboh.json -o jonboh.c
cd ../../../../../../
qmk flash -kb handwired/dactyl_manuform/4x6 -km jonboh -j 8

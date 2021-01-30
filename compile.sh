#!/bin/bash
USER=ledesmablt
if [ "$1" == "kbd75" ]; then
  KB=kbdfans/kbd75/rev2
  OUTPUT=kbdfans_kbd75_rev2_ledesmablt.hex
elif [ "$1" == "planck" ]; then
  KB=planck/rev6
  OUTPUT=planck_rev6_ledesmablt.bin
else
  echo 'Please provide a keyboard!'
  exit 1
fi

qmk compile -kb $KB -km $USER && \
 cp .build/$OUTPUT ~/downloads/

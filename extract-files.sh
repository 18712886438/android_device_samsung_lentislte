#!/bin/bash

set -e

export VENDOR=samsung
export DEVICE=lentislte

function extract() {
    for FILE in `egrep -v '(^#|^$)' $1`; do
        OLDIFS=$IFS IFS=":" PARSING_ARRAY=($FILE) IFS=$OLDIFS
        FILE=`echo ${PARSING_ARRAY[0]} | sed -e "s/^-//g"`
        DEST=${PARSING_ARRAY[1]}
        if [ -z $DEST ]; then
            DEST=$FILE
        fi
        DIR=`dirname $FILE`
        if [ ! -d $2/$DIR ]; then
            mkdir -p $2/$DIR
        fi
        # Try CM target first
        cp /home/callmesuper/flyme/devices/lentislte/vendor/system/$DEST $2/$DEST
        # if file does not exist try OEM target
        if [ "$?" != "0" ]; then
            cp /home/callmesuper/flyme/devices/lentislte/vendor/system/$FILE $2/$DEST
        fi
    done
}



DEVBASE=../../../vendor/$VENDOR/$DEVICE/proprietary
rm -rf $DEVBASE/*

extract ../../$VENDOR/$DEVICE/proprietary-files.txt $DEVBASE

./../../$VENDOR/$DEVICE/setup-makefiles.sh

#!/bin/sh

set -e

export VENDOR=samsung
export DEVICE=lentislte
./../../$VENDOR/lentislte-common/extract-files.sh $@

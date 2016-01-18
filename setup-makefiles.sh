#!/bin/sh

set -e

export VENDOR=samsung
export DEVICE=lentislte
./../../$VENDOR/lentislte-common/setup-makefiles.sh $@

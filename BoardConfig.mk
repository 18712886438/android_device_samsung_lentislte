#
# Copyright (C) 2015 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# inherit from common trlte
-include device/samsung/lentislte-common/BoardConfigCommon.mk

TARGET_OTA_ASSERT_DEVICE := lentislteskt,lentisltektt,lentisltelgt,lentislte

# Kernel
TARGET_ARCH := arm
TARGET_KERNEL_CONFIG := cm_lentislte_defconfig

# Init
TARGET_INIT_VENDOR_LIB := libinit_lentislte
TARGET_RECOVERY_DEVICE_MODULES := libinit_lentislte
TARGET_UNIFIED_DEVICE := true

# Radio
BOARD_RIL_CLASS := ../../../device/samsung/lentislte/ril

# inherit from the proprietary version
-include vendor/samsung/lentislte/BoardConfigVendor.mk

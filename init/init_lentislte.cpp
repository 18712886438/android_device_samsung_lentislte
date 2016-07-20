/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void gsm_properties()
{
    property_set("telephony.lteOnGsmDevice", "1");
    property_set("ro.telephony.default_network", "9");
}

void vendor_load_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "G906K")) {
        property_set("ro.build.fingerprint", "samsung/lentisltektt/lentisltektt:6.0.1/LRX22C/G906KKTU1BOI5:user/release-keys");
        property_set("ro.build.description", "lentisltektt-user 6.0.1 LRX22C G906KKTU1BOI5 release-keys");
        property_set("ro.product.model", "SM-G906K");
        property_set("ro.product.device", "lentisltektt");
        gsm_properties();
    } else if (strstr(bootloader, "G906S")) {
        property_set("ro.build.fingerprint", "samsung/lentislteskt/lentislteskt:6.0.1/MRA58K/G906SKSU1BOI5:user/release-keys");
        property_set("ro.build.description", "lentislteskt-user 6.0.1 MRA58K G906SKSU1BOI5 release-keys");
        property_set("ro.product.model", "SM-G906S");
        property_set("ro.product.device", "lentislteskt");
        gsm_properties();
    } else {
        property_set("ro.build.fingerprint", "samsung/lentisltelgt/lentisltelgt:6.0.1/KVT49L/G906LKLU1ANG8:user/release-keys");
        property_set("ro.build.description", "lentisltelgt-user 6.0.1 KVT49L G906LKLU1ANG8 release-keys");
        property_set("ro.product.model", "SM-G906L");
        property_set("ro.product.device", "lentisltelgt");
        gsm_properties();
    }

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    INFO("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}

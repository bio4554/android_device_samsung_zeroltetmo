/*
   Copyright (c) 2015, The Dokdo Project. All rights reserved.

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

   File Name : init_sec.c
   Create Date : 2015.11.03
   Author : Sunghun Ra
 */

#include <stdlib.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void vendor_load_properties()
{
    char platform[PROP_VALUE_MAX];
    char bootloader[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];

    property_get("ro.bootloader", bootloader);

    if (strstr(bootloader, "G925T")) {
        /* zeroltetmo */
        property_set("ro.build.fingerprint", "samsung/zeroltetmo/zeroltetmo:5.1.1/LRX22G/G925TUVU3DOJ7:user/release-keys");
        property_set("ro.build.description", "zeroflteskt-user 5.1.1 LRX22G G925TUVU3DOJ7 release-keys");
        property_set("ro.product.model", "SM-G925T");
        property_set("ro.product.device", "zeroltetmo");
    } else {
        /* zerofltexx */
        property_set("ro.build.fingerprint", "samsung/zerofltexx/zerofltexx:5.0.2/LRX22G/G920FKSU1AOF5:user/release-keys");
        property_set("ro.build.description", "zerofltexx-user 5.0.2 LRX22G G920FKSU1AOF5 release-keys");
        property_set("ro.product.model", "SM-G920F");
        property_set("ro.product.device", "zerofltexx");
    }

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    ERROR("Found bootloader id %s setting build properties for %s device\n", bootloader, devicename);
}

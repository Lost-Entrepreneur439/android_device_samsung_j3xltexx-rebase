/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.
   Copyright (c) 2017-2020, The LineageOS Project. All rights reserved.

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

#include <android-base/file.h>
#include <android-base/logging.h>
#include <android-base/strings.h>
#include <android-base/properties.h>

#include "init_universal3475.h"

using android::base::GetProperty;
using android::base::ReadFileToString;
using android::base::Trim;

void vendor_load_properties()
{
    std::string bootloader = GetProperty("ro.bootloader", "");

    if (bootloader.find("J320A") == 0) {
        /* j3xlteatt */
        property_override("ro.build.description", "j3xlteuc-user 7.1.1 NMF26X J320AUCU3BVH1 release-keys");
        set_ro_product_prop("device", "j3xlteatt");
        set_ro_build_prop("fingerprint", "samsung/j3xlteuc/j3xlteatt:7.1.1/NMF26X/J320AUCU3BVH1:user/release-keys");
        set_ro_product_prop("model", "SAMSUNG-SM-J320A");
        set_ro_product_prop("name", "j3xlteuc");
        gsm_properties("9,1");
    } else if (bootloader.find("J320AZ") == 0) {
        /* j3xlteaio */
        property_override("ro.build.description", "j3xltetu-user 7.1.1 NMF26X J320AZTUU3BVH1 release-keys");
        set_ro_product_prop("device", "j3xlteaio");
        set_ro_build_prop("fingerprint", "samsung/j3xltetu/j3xlteaio:7.1.1/NMF26X/J320AZTUU3BVH1:user/release-keys");
        set_ro_product_prop("model", "SAMSUNG-SM-J320AZ");
        set_ro_product_prop("name", "j3xltetu");
        gsm_properties("9,1");
    } else if (bootloader.find("J320W8") == 0) {
        /* j3xltebmc */
        property_override("ro.build.description", "j3xltebmc-user 7.1.1 NMF26X J320W8VLU2BQK1 release-keys");
        set_ro_product_prop("device", "j3xltebmc");
        set_ro_build_prop("fingerprint", "samsung/j3xltebmc/j3xltebmc:7.1.1/NMF26X/J320W8VLU2BQK1:user/release-keys");
        set_ro_product_prop("model", "SM-J320W8");
        set_ro_product_prop("name", "j3xltebmc");
        gsm_properties("9,1");
    } else {
        gsm_properties("9,1");
    }

    std::string device = GetProperty("ro.product.device", "");
    LOG(ERROR) << "Found bootloader id " << bootloader <<  " setting build properties for "
        << device <<  " device" << std::endl;
}

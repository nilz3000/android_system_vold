/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <map>
#include <string>
#include <vector>

#include <cutils/multiuser.h>
#include <fscrypt/fscrypt.h>

bool fscrypt_initialize_systemwide_keys();

bool fscrypt_init_user0();
extern bool fscrypt_init_user0_done;
bool fscrypt_vold_create_user_key(userid_t user_id, int serial, bool ephemeral);
bool fscrypt_destroy_user_key(userid_t user_id);
bool fscrypt_add_user_key_auth(userid_t user_id, int serial, const std::string& secret);
bool fscrypt_clear_user_key_auth(userid_t user_id, int serial, const std::string& secret);
bool fscrypt_fixate_newest_user_key_auth(userid_t user_id);

std::vector<int> fscrypt_get_unlocked_users();
bool fscrypt_unlock_user_key(userid_t user_id, int serial, const std::string& secret);
bool fscrypt_lock_user_key(userid_t user_id);

bool fscrypt_prepare_user_storage(const std::string& volume_uuid, userid_t user_id, int serial,
                                  int flags);
bool fscrypt_destroy_user_storage(const std::string& volume_uuid, userid_t user_id, int flags);

bool fscrypt_destroy_volume_keys(const std::string& volume_uuid);
bool is_metadata_wrapped_key_supported();
bool lookup_key_ref(const std::map<userid_t, android::fscrypt::EncryptionPolicy>& key_map, userid_t user_id,
                           std::string* raw_ref);

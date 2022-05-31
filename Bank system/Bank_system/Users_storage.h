#ifndef UNTITLED4_USERS_STORAGE_H
#define UNTITLED4_USERS_STORAGE_H

#include <map>
#include "user_info.h"

class Users_storage {
public:
    std::map<std::string, user_info*> users = {};

    Users_storage() = default;

    ~Users_storage() { users.clear(); }
};


#endif //UNTITLED4_USERS_STORAGE_H

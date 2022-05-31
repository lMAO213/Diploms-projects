#ifndef UNTITLED4_BUILD_USER_H
#define UNTITLED4_BUILD_USER_H

#include "Users_storage.h"

//--------------------------------------------------------Build User----------------------------------------------------

class Build_user{
public:
    user_info* adding_user_info(user_info* user);

    user_info* add_new_user(const std::string input_fullname);
};


#endif //UNTITLED4_BUILD_USER_H

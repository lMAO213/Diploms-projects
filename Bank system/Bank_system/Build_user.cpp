#include "Console.h"
#include "Build_user.h"

Users_storage user_storage;

//--------------------------------------------------------Build User----------------------------------------------------

user_info* Build_user::adding_user_info(user_info* user) {
    std::pair<std::string, std::pair<std::string, std::string> > more_info = Console::more_info();

    std::string input_passport_series = more_info.second.first;
    std::string input_passport_num = more_info.second.second;
    std::string input_address = more_info.first;

    return new user_info(user->fullname,
                                        input_passport_series,
                                        input_passport_num,
                                        input_address);
}

user_info* Build_user::add_new_user(const std::string input_fullname) {
    user_storage.users[input_fullname] = new user_info(input_fullname);

    return user_storage.users[input_fullname];
}

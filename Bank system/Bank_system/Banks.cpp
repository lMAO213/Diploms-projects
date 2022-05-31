#include "Banks.h"

Bank_account_factory baf;
Transferring transfer;
Build_user bu;
Users_storage us;

static const std::string_view KEY_END = "end";
static const std::string_view KEY_TRANSFER = "1";
static const std::string_view KEY_ADD_INFO = "2";
static const std::string_view KEY_CREATE_BANK_ACCOUNT = "3";
static const std::string_view KEY_PRINT_USER = "4";
static const std::string_view KEY_SET_LIMIT = "5";

void Usual_functions::registering(const std::string& user_name) {

    cur_user = bu.add_new_user(user_name);
    us.users[user_name] = bu.adding_user_info(cur_user);
    cur_user = us.users[user_name];
}

void Usual_functions::bank_menu(const std::string& user_name,
                                const size_t credit_limit,
                                const double percent_of_deposit) {
    std::string command;

    if(us.users.find(user_name) == us.users.end()) {
        registering(user_name);
    }

    command = Console::updated_bank_menu(user_name);

    while (command != KEY_END) {

        if(command == KEY_TRANSFER) {
            transfer.transferring(cur_user);
        } else if (command == KEY_ADD_INFO) {

            cur_user = bu.adding_user_info(cur_user);
        } else if (command == KEY_CREATE_BANK_ACCOUNT) {

            baf.creating_bank_account(cur_user, credit_limit,
                                                        cur_user->level_of_trust? percent_of_deposit: 0);
        } else if (command == KEY_PRINT_USER) {
            Console::print_user(cur_user);
        } else if (command == KEY_SET_LIMIT) {
            int limit = Console::set_limit(cur_user);

            if(limit >= 0) cur_user->limit = limit;
            else cur_user->limit = INT_MAX;
        }

        command = Console::updated_bank_menu(user_name);
    }
}

//--------------------------------------------------------First bank----------------------------------------------------

void Money_bank::Money_bank_menu(const std::string fullname) {
    bank_menu(fullname, credit_limit, percent_of_deposit);
}

//--------------------------------------------------------Second bank---------------------------------------------------

void Polish_bank::Polish_bank_menu(const std::string& user_name) {
    bank_menu(user_name, credit_limit, percent_of_deposit);
}

//--------------------------------------------------------Third bank----------------------------------------------------

void Jewish_bank::Jewish_bank_menu(const std::string& user_name) {
    bank_menu(user_name, credit_limit, percent_of_deposit);
}

//--------------------------------------------------------Bank system---------------------------------------------------

void Banks::work_of_app(const std::string &command) {

    const std::string_view key_jew_bank = "Jewish";
    const std::string_view key_pol_bank = "Polish";
    const std::string_view key_mon_bank = "Money";

    const std::string_view key_jew_bank_num = "1";
    const std::string_view key_pol_bank_num = "2";
    const std::string_view key_mon_bank_num = "3";

    std::string user_name = Console::fullname();
    if (command == key_jew_bank or command == key_jew_bank_num) {
        Jewish_bank_menu(user_name);
    } else if (command == key_pol_bank or command == key_pol_bank_num) {
        Polish_bank_menu(user_name);
    } else if (command == key_mon_bank or command == key_mon_bank_num) {
        Money_bank_menu(user_name);
    }
}

void Banks::Banks_system_menu() {
    std::string command = Console::choose_bank();
    while (command != "end") {
        work_of_app(command);
        command = Console::choose_bank();
    }

    std::cout << "bye";
}

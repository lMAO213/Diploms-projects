#ifndef UNTITLED4_CONSOLE_H
#define UNTITLED4_CONSOLE_H

#include "Users_storage.h"
#include <unordered_set>

//--------------------------------------------------------Achievements--------------------------------------------------
/*
    1) сделал меню банка
    2) сделал ввод имени
    3) сделал ввод доп информации
    4) создал создание счета
    5) сделал меню системы
    6) сделал операции банка
    7) сделал вывод аккаунта пользователя
*/
//--------------------------------------------------------Console-------------------------------------------------------

class Console {
public:

    //--------------------------------------------------------Transfer outputs------------------------------------------

    static std::string transferring();


    static std::string write_type_of_card();

    //--------------------------------------------------------Bank menu-------------------------------------------------

    static std::string bank_menu(const std::string& fullname);

    static std::string updated_bank_menu(const std::string& fullname);

    static int set_limit(user_info* user);

    //--------------------------------------------------------User input------------------------------------------------

    static std::string fullname();

    //--------------------------------------------------------Add info--------------------------------------------------

    static std::pair<std::string, std::pair<std::string, std::string> > more_info();

    static std::pair<std::string, std::pair<std::string, std::string> > info();

    //-----------------------------------------------------Output User account------------------------------------------

    static void print_user(const user_info* user);

    //--------------------------------------------------------Create bank account---------------------------------------

    static std::string creating_bank_account(const std::string& fullname);

    //--------------------------------------------------------Main menu-------------------------------------------------

    static std::string choose_bank();

    static size_t write_val();

    static std::string write_another_user();

    //--------------------------------------------------------- Errors -------------------------------------------------

    static void transfer_denied(const std::string& type);

    static void do_not_have_a_card();

};

#endif //UNTITLED4_CONSOLE_H

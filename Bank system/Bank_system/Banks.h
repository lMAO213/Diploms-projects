#ifndef UNTITLED4_BANKS_H
#define UNTITLED4_BANKS_H

#include "Transferring.h"
#include "Bank_account_factory.h"
#include "Build_user.h"


class Usual_functions {
public:
    void bank_menu (const std::string& user_name, const size_t credit_limit, const double percent_of_deposit);

    void registering(const std::string& user_name);

private:
    user_info* cur_user = nullptr;
};

//--------------------------------------------------------First bank----------------------------------------------------

class Money_bank: virtual public Usual_functions {
public:
    void Money_bank_menu(const std::string fullname);

private:
    const int credit_limit = 20000;
    const double percent_of_deposit = 0.015;

};

//--------------------------------------------------------Second bank---------------------------------------------------

class Polish_bank: virtual public Usual_functions {
public:
    void Polish_bank_menu(const std::string& user_name);

private:
    const int credit_limit = 30000;
    const double percent_of_deposit = 0.02;
};

//--------------------------------------------------------Third bank----------------------------------------------------

class Jewish_bank: virtual public Usual_functions {
public:
    void Jewish_bank_menu(const std::string& user_name);

private:
    const int credit_limit = 10000;
    const double percent_of_deposit = 0.03;
};

//--------------------------------------------------------Bank system---------------------------------------------------

class Banks: private Money_bank, private Polish_bank, private Jewish_bank {
public:
    void Banks_system_menu();

    void work_of_app(const std::string &command);

};

#endif //UNTITLED4_BANKS_H

#ifndef UNTITLED4_USER_INFO_H
#define UNTITLED4_USER_INFO_H

#include <iostream>
#include <string>
#include <ctime>

struct cash_limit {
    int limit = INT_MAX;

    void update_limit(int _limit);
};

struct months {
    short month = 0;

    months() = default;

    void updated_month();
};

struct expenses {
    int expenses_for_the_month = 0;

    void update_expenses();
};

struct user_info: public expenses, public cash_limit, public months {
    std::string fullname = "";
    std::string passport_series = "";
    std::string passport_num = "";
    std::string address = "";
    bool level_of_trust = false;
    bool having_debit_account = false;
    size_t debit_account = 0;
    bool having_deposit = false;
    double deposit = 0;
    bool having_credit_account = false;
    int credit_account = 0;

    user_info() = default;

    user_info(const std::string& input_fullname,
              const std::string& input_passport_series,
              const std::string& input_passport_num,
              const std::string& input_address):
            fullname(input_fullname),
            passport_series(input_passport_series),
            passport_num(input_passport_num),
            address(input_address),
            level_of_trust(true) {}

    explicit user_info(const std::string& input_fullname): fullname(input_fullname) {}
};

#endif //UNTITLED4_USER_INFO_H

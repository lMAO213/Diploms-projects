#ifndef UNTITLED4_BANK_ACCOUNT_FACTORY_H
#define UNTITLED4_BANK_ACCOUNT_FACTORY_H

#include "Console.h"

//--------------------------------------------------------Create bank account-------------------------------------------

class Debit_factory {
public:
    void create_debit_account(user_info* user);

};

class Credit_factory {
public:
    void crate_credit_account(user_info*& user, int credit_val);

};

class Deposit_factory{
public:
    void create_deposit(user_info* user);

    void deposit_increasing(user_info* user, double percent_of_deposit, double  coef_of_increasing);

};

class Bank_account_factory: private Debit_factory, private Credit_factory, public Deposit_factory{
public:
    void creating_bank_account(user_info* user, const int& credit_limit, const double& percent_of_deposit);

    void deposit_increase(user_info* user, double percent_of_deposit, int time_start, int time_end);

};

#endif //UNTITLED4_BANK_ACCOUNT_FACTORY_H

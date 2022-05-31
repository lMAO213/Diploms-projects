#include "Bank_account_factory.h"

static const std::string_view KEY_ONE = "1";
static const std::string_view KEY_TWO = "2";

//--------------------------------------------------------Create bank account-------------------------------------------

void Debit_factory::create_debit_account(user_info* user) {
    user->having_debit_account = true;
}

void Credit_factory::crate_credit_account(user_info*& user, int credit_val) {
    user->having_credit_account = true;
    user->credit_account = credit_val;
}

void Deposit_factory::create_deposit(user_info* user) {
    if(user->level_of_trust) {
        user->having_deposit = true;
    }
}

void Deposit_factory::deposit_increasing(user_info* user, const double percent_of_deposit, const double  coef_of_increasing) {
    double tmp = percent_of_deposit * coef_of_increasing;
    user->deposit += user->deposit * tmp;
}

void Bank_account_factory::creating_bank_account(user_info* user, const int& credit_limit, const double& percent_of_deposit) {
    std::string option = Console::creating_bank_account(user->fullname);

    /*
     "Choose one of possibilities (write number): \n"
                 "1) Create debit\n"
                 "2) Create credit\n"
                 "3) Create deposit\n";
     */

    if (option == KEY_ONE) {
        if(!user->having_debit_account) {
            create_debit_account(user);
        }
    } else if (option == KEY_TWO) {
        if (!user->having_credit_account) {
            crate_credit_account(user, credit_limit);
        }
    } else {
        if (!user->having_deposit and user->level_of_trust) {
            create_deposit(user);
        }
    }

    if(user->month == 0) {
        user->update_expenses();
    }

    time_t now = time(0);
    tm* lct = localtime(&now);

    short cur_month = 1 + lct->tm_mon;

    if(user->month != cur_month) {
        user->update_expenses();
    }
}

void Bank_account_factory::deposit_increase(user_info* user, const double percent_of_deposit,
                                            int time_start = clock(), int time_end = clock()) {
    int t_s_sec = time_start / CLOCKS_PER_SEC;
    int t_e_sec = time_start / CLOCKS_PER_SEC;
    double coefficient = (t_e_sec - t_s_sec) % 10;
    deposit_increasing(user, percent_of_deposit, coefficient);
}
#include "Transferring.h"

Users_storage us_t;

static const std::string_view KEY_ONE = "1";
static const std::string_view KEY_TWO = "2";
static const std::string_view KEY_THREE = "3";
static const std::string_view KEY_FOUR = "4";

//--------------------------------------------------------Transferring method-------------------------------------------

void Cash_withdrawal::cash_withdrawal(user_info* user, const std::string& type_of_card, const size_t& val)  {
    /*
    "1) Debit"
    "2) Credit"
    "3) Deposit"
     */
    if (type_of_card == KEY_THREE) {
        Console::transfer_denied(type_of_card);
    } else if (type_of_card == KEY_TWO) {
        if (user->level_of_trust) {
            user->credit_account -= val;
        } else {
            Console::transfer_denied(type_of_card);
        }
    } else {
        if (user->debit_account < val) {
            Console::transfer_denied(type_of_card);
        } else {
            user->debit_account -= val;
        }
    }
}

void Transfer_to_another::transfer_to_people(user_info* user, user_info* another_user,
                                             const std::string& type_of_current_user_card,
                                             const size_t& val) {
    /*
    "1) Debit"
    "2) Credit"
    "3) Deposit"
     */
    if(user->expenses_for_the_month <= user->limit) {
        Console::transfer_denied("4");
        return;
    }

    if (type_of_current_user_card == KEY_TWO) {
        another_user->debit_account += val;
        user->credit_account -= val;

        user->expenses_for_the_month += val;
    } else if (type_of_current_user_card == KEY_ONE) {
        another_user->debit_account += val;
        user->debit_account -= val;

        user->expenses_for_the_month += val;
    } else if (type_of_current_user_card == KEY_THREE) {
        Console::transfer_denied(type_of_current_user_card);
    }
}

void Cancellation_of_transaction::cancellation_of_the_transaction(user_info* user, user_info* another_user,
                                                                  const std::string& type_of_current_user_card,
                                                                  const size_t& val) {
    /*
    "1) Debit"
    "2) Credit"
    "3) Deposit"
     */
    if (type_of_current_user_card == KEY_TWO) {
        another_user->debit_account -= val;
        user->credit_account += val;
    } else  if (type_of_current_user_card == KEY_ONE){
        another_user->debit_account -= val;
        user->debit_account += val;
    }
}

void Balance_replenishment::balance_replenishment(user_info* user) {
    /*
    "1) Debit"
    "2) Credit"
    "3) Deposit"
     */

    std::string type_of_card = Console::write_type_of_card();

    if (type_of_card == KEY_THREE and user->having_deposit) {
        size_t val = Console::write_val();
        user->deposit += val;
    }
    else if (type_of_card == KEY_TWO and user->having_credit_account) {
        size_t val = Console::write_val();
        user->credit_account += val;
    }

    else if(type_of_card == KEY_ONE and user->having_debit_account) {
        size_t val = Console::write_val();
        user->debit_account += val;
    }
    else
        balance_replenishment(user);

}

void Transferring::transferring(user_info* user) {
    if(!(user->having_debit_account or
         user->having_credit_account or user->having_deposit)) {
        Console::do_not_have_a_card();
        return;
    }
    /*
    "1) Balance replenishment\n"
    "2) Cancellation of transaction\n"
    "3) Transfer to another\n"
    "4) Cash withdrawal"
     */

    std::string option = Console::transferring();

    if (option == KEY_ONE) {
        balance_replenishment(user);

    } else if (option == KEY_TWO) {
        std::string type_of_card = Console::write_type_of_card();
        std::string another_user = Console::fullname();

        size_t val = Console::write_val();

        if(us_t.users.find(another_user) != us_t.users.end()) {
            cancellation_of_the_transaction(user, us_t.users[another_user], type_of_card, val);
        }
    } else if (option == KEY_THREE) {
        std::string type_of_card = Console::write_type_of_card();

        std::string another_user = Console::write_another_user();
        size_t val = Console::write_val();

        transfer_to_people(user, us_t.users[another_user], type_of_card, val);
    } else  if (option == KEY_FOUR){
        size_t val = Console::write_val();
        std::string type_of_card = Console::write_type_of_card();

        cash_withdrawal(user, type_of_card, val);
    }
}
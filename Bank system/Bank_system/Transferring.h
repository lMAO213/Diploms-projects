#ifndef UNTITLED4_TRANSFERRING_H
#define UNTITLED4_TRANSFERRING_H

#include "Console.h"

//--------------------------------------------------------Transferring method-------------------------------------------
class Cash_withdrawal {
public:
    void cash_withdrawal(user_info* user, const std::string& type_of_card, const size_t& val);
};

class Transfer_to_another {
public:
    void transfer_to_people(user_info* user, user_info* another_user,
                            const std::string& type_of_current_user_card, const size_t& val);
};

class Cancellation_of_transaction {
public:
    void cancellation_of_the_transaction(user_info* user, user_info* another_user,
                                         const std::string& type_of_current_user_card, const size_t& val);
};

class Balance_replenishment {
public:
    void balance_replenishment(user_info* user);
};


class Transferring: private Cash_withdrawal, private Cancellation_of_transaction,
                    private Transfer_to_another, private Balance_replenishment {
public:
    void transferring(user_info* user);
};

#endif //UNTITLED4_TRANSFERRING_H

#include "user_info.h"

void cash_limit::update_limit(int _limit) {
    limit = _limit;
}

void months::updated_month() {
    time_t now = time(0);
    tm* lct = localtime(&now);

    month = 1 + lct->tm_mon;
}

void expenses::update_expenses() {
    expenses_for_the_month = 0;
}

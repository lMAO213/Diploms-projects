#include "Console.h"

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

std::ostream& operator<<(std::ostream& out, const user_info* user) {
    out << "Welcome, " << user->fullname << '\n' <<
              "1) Debit: " << user->debit_account << '\n' <<
              "2) Credit: " << user->credit_account << '\n' <<
              "3) Deposit: " << user->deposit << '\n' <<
              '\n' <<
              "1) User address: " <<

    ((user->address.empty())? "---" : user->address) << '\n' <<

    "2) User passport series: " <<

    ((user->passport_series.empty())? "---" : user->passport_series) << '\n' <<

    "3) User passport num: " <<

    ((user->passport_num.empty())? "---\n" : user->passport_num) << '\n' <<

    "How much money has been spent this month: " << user->expenses_for_the_month << '\n' <<

    "(write end to return to menu)\n";

    return out;
}

static const std::string_view KEY_END = "end";
static const std::string_view KEY_NO = "no";
static const std::string_view KEY_YES = "yes";

static const std::string_view KEY_ONE = "1";
static const std::string_view KEY_TWO = "2";
static const std::string_view KEY_THREE = "3";
static const std::string_view KEY_FOUR = "4";
static const std::string_view KEY_FIVE = "5";

//--------------------------------------------------------Transfer outputs------------------------------------------

std::string Console::transferring() {
    system("clear");
    std::string option;

    std::cout << "Replenishment of the balance(write a number):\n"
                 "1) Balance replenishment\n"
                 "2) Cancellation of transaction\n"
                 "3) Transfer to another\n"
                 "4) Cash withdrawal\n";
    std::cin >> option;
    std::cout << '\n';

    if(option == KEY_ONE or
    option == KEY_TWO or
    option == KEY_THREE or
    option == KEY_FOUR)
        return option;
    else
        return transferring();
}

std::string Console::write_type_of_card() {
    system("clear");

    std::string type_of_card;
    std::cout << "Select card(write a number):\n"
                 "1) Debit\n"
                 "2) Credit\n"
                 "3) Deposit\n";
    std::cin >> type_of_card;
    std::cout << '\n';

    if(type_of_card == KEY_ONE or
    type_of_card == KEY_TWO or
    type_of_card == KEY_THREE)

        return type_of_card;
    else
        return write_type_of_card();
}

//--------------------------------------------------------Bank menu-------------------------------------------------

std::string Console::bank_menu(const std::string& fullname) {
    system("clear");
    std::cout << "Welcome, " << fullname << "\n";
    std::cout << "Do you want to create an account? (write yes / no," <<
              "\nor end to return to main menu): ";

    std::string having;
    std::cin >> having;
    std::cout << '\n';

    if (having == KEY_END)
        return "end";

    if (having == KEY_NO)
        return "no";

    if (having ==  KEY_YES)
        return "yes";

    return bank_menu(fullname);
}

int Console::set_limit(user_info* user) {
    system("clear");
    std::cout << "Write the limit(write num < than 0 to remove limit): ";

    int limit;
    std::cin >> limit;

    return limit;
}

std::string Console::updated_bank_menu(const std::string& fullname) {
    system("clear");
    std::cout << "Welcome, " << fullname << "!\n"
                                            "Choose one option(write number\n"
                                            "or end to return to the menu):\n"
                                            "1) Transfer money\n"
                                            "2) Update info\n"
                                            "3) Create bank account\n"
                                            "4) Checkout user profile\n"
                                            "5) Set limit on card\n";

    std::string option;
    std::cin >> option;
    std::cout << '\n';

    if(option == KEY_ONE or
    option == KEY_TWO or
    option == KEY_THREE or
    option == KEY_FOUR or
    option == KEY_FIVE or
    option == KEY_END)

        return option;
    else
        return updated_bank_menu(fullname);
}

//--------------------------------------------------------User input------------------------------------------------

std::string Console::fullname() {
    system("clear");
    std::cout << "Write your name and surname (Ivan_Ivanov): " << '\n';
    std::string fullname;
    std::cin >> fullname;
    return fullname;
}

//--------------------------------------------------------Add info--------------------------------------------------

int checking_for_matches(std::string argv) {
    size_t cnt = 0;
    std::unordered_set<char> all_num = {'0', '1', '2', '3', '4',
                                        '5', '6', '7', '8', '9'};

    for(auto& i : argv) {
        if(all_num.find(i) != all_num.end()) cnt++;
    }

    return cnt;
}

std::pair<std::string, std::pair<std::string, std::string> > Console::info() {

    system("clear");
    std::cout << "Write your address and passport data\n" <<
              "address(city_street_house): ";

    std::string address;
    std::cin >> address;

    std::cout << "Passport series: ";
    std::string passport_series;
    std::cin >> passport_series;

    std::cout << "\nPassport num: ";
    std::string passport_num;
    std::cin >> passport_num;

    if(checking_for_matches(passport_series) != 4 or
    checking_for_matches(passport_num) != 6) {
        return info();
    }

    return {address, {passport_series, passport_num}};
}

std::pair<std::string, std::pair<std::string, std::string> > Console::more_info() {
    system("clear");

    std::cout << "Do you want to add more info (address and passport data)? (Write yes / no): " << '\n';
    std::string accept;
    std::cin >> accept;

    if(accept == KEY_NO) {
        return std::make_pair("", std::make_pair("", ""));
    }
    if(accept != KEY_YES)
        return more_info();

    return info();
}

//-----------------------------------------------------Output User account------------------------------------------

void Console::print_user(const user_info* user) {
    system("clear");

    std::cout << user;

    std::string ending;
    std::cin >> ending;


    if(ending == KEY_END)
        return;
    else
        print_user(user);
}

//--------------------------------------------------------Create bank account---------------------------------------

std::string Console::creating_bank_account(const std::string& fullname) {
    system("clear");

    std::cout << "Welcome, " << fullname << "!\n";
    std::cout << "Choose one of possibilities (write number): \n"
                 "1) Create debit\n"
                 "2) Create credit\n"
                 "3) Create deposit\n";

    std::string choice;
    std::cin >> choice;
    std::cout << '\n';

    if(choice == KEY_ONE or
    choice == KEY_TWO or
    choice == KEY_THREE)

        return choice;
    else
        return creating_bank_account(fullname);
}

//--------------------------------------------------------Main menu-------------------------------------------------

std::string Console::choose_bank() {
    system("clear");

    std::cout << "Select only 1 bank (Yes, you can be user of only one bank ;)," <<
              "\nor write end to close the app) :\n"
              "1) Jewish\n"
              "2) Polish\n"
              "3) Money\n";

    std::string command;
    std::cin >> command;

    const std::string_view key_jew_bank = "Jewish";
    const std::string_view key_pol_bank = "Polish";
    const std::string_view key_mon_bank = "Money";

    if((command == key_jew_bank or command == KEY_ONE)
    or (command == key_pol_bank or command == KEY_TWO)
    or (command == key_mon_bank or command == KEY_THREE)
    or command == KEY_END)
        return command;
    else
        return choose_bank();
}

size_t Console::write_val() {
    system("clear");
    std::cout << "Write sum of replacement: ";

    size_t val;
    std::cin >> val;
    std::cout << '\n';

    return val;
}

std::string Console::write_another_user() {
    system("clear");

    std::cout << "Enter the fullname of the person\n"
                 "to whom the money was sent by mistake: ";

    std::string another_user;
    std::cin >> another_user;

    return another_user;
}
//--------------------------------------------------------- Errors -------------------------------------------------

void Console::transfer_denied(const std::string& type) {
    system("clear");

    if (type == KEY_ONE)
        std::cout << "You can't take money from this card\n";

    else if (type == KEY_TWO)
        std::cout << "You can't use this card, because fields passport's "
                     "data and address are empty\n";

    else if (type == KEY_THREE)
        std::cout << "You don't have enough cash\n";

    else if (type == KEY_FOUR)
        std::cout << "You have already reached the limit\n";

    std::cout << "Write end to go back to menu\n";
    std::string end;

    std::cin >> end;



    if(end == KEY_END)
        return;
    else
        transfer_denied(type);
}

void Console::do_not_have_a_card() {
    system("clear");
    std::cout << "You do not have a card\n"
                 "Write end to go back to menu\n";
    std::string end;
    std::cin >> end;

    if(end == KEY_END)
        return;
    else
        do_not_have_a_card();
}

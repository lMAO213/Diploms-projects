from math import floor
from os import system
from sys import exit, platform
from time import time

from keyboard import is_pressed

# --------------------------------------------- Global elements --------------------------------------------------------

cnt_of_presses = 0
lvl_of_autoclick = 1
price = 10

# --------------------------------------------- Checking for OS --------------------------------------------------------

clear = ''
if platform == "linux" or \
        platform == "linux2" or platform == "darwin":
    clear = 'clear'
else:
    clear = 'cls'


# --------------------------------------------- Main functions ---------------------------------------------------------


def close_game():
    print('bye')
    exit()


def menu():
    global clear
    global cnt_of_presses
    system(clear)
    print('Use 1 to open store and Esc to leave the game')
    print("Amount of clicks:", cnt_of_presses)


def shop():
    global clear
    global price
    global cnt_of_presses
    global lvl_of_autoclick

    system(clear)
    if lvl_of_autoclick > 2:
        print("{} Lv Auto click".format("max"))
    else:
        print("{} Lv Auto click cost is {} clicks: (press 3 to buy)".format(lvl_of_autoclick, price))

    print("Amount of clicks:", cnt_of_presses)
    print("To close the store press 2")


# --------------------------------------------- Checking for OS --------------------------------------------------------


click_interval = 10
time_interval_1 = int(floor(time()))
auto_click = 0
amount_of_increase = 1
in_menu = True

menu()

while True:

    is_smth_changed = False

    # --------------------------------------------- Menu navigation ----------------------------------------------------

    end_form_while = False

    while 1 - is_pressed('space'):

        is_smth_changed = False

        # --------------------------------------------- End of game ----------------------------------------------------

        if is_pressed('esc'):
            close_game()

        # --------------------------------------------- Auto clicker ---------------------------------------------------

        if auto_click >= 1:
            time_interval_2 = int(floor(time()))
            if time_interval_2 - time_interval_1 >= click_interval:
                cnt_of_presses += amount_of_increase
                if not in_menu:
                    shop()
                else:
                    menu()
                time_interval_1 = time_interval_2

        # --------------------------------------------- Changing menus -------------------------------------------------

        while is_pressed('1'):
            in_menu = False
            is_smth_changed = True

        while is_pressed('2'):
            in_menu = True
            is_smth_changed = True

        if is_smth_changed:
            if in_menu:
                menu()
            else:
                shop()

        # --------------------------------------------- Buying ---------------------------------------------------------

        while is_pressed('3') and not in_menu and not end_form_while:

            if cnt_of_presses >= price and auto_click == 0:  # 1st lvl
                cnt_of_presses -= price
                auto_click = 1
                price += 30
                lvl_of_autoclick += 1

            elif cnt_of_presses >= price and auto_click == 1:  # 2st lvl
                lvl_of_autoclick += 1
                amount_of_increase = 2
                cnt_of_presses -= price
                auto_click = 2

            elif auto_click < 2 and cnt_of_presses < price:  # lack of money
                system(clear)
                print('You do not have enough clicks')

            end_from_while = True

    # --------------------------------------------- When "space" is pressed --------------------------------------------

    while is_pressed('space'):
        is_smth_changed = True
        pass

    # --------------------------------------------- Menu navigation ----------------------------------------------------

    if not is_smth_changed:
        pass

    if in_menu:
        cnt_of_presses += 1
        menu()
    else:
        shop()

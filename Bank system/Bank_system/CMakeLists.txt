cmake_minimum_required(VERSION 3.20)
project(untitled4)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled4 main.cpp
#        убрать библиотеки и перечислить все тут
        Bank_account_factory.cpp
        Banks.cpp
        Transferring.cpp
        Build_user.cpp
        Console.cpp user_info.cpp)
#target_link_libraries(untitled4)
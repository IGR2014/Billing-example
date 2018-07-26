cmake_minimum_required(VERSION 2.8)

project(Billing-example)

set(SOURCE_EXE main.cpp MobileNumber.cpp Currency.cpp CallInfo.cpp)

add_executable(main ${SOURCE_EXE})


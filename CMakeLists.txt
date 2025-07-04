cmake_minimum_required(VERSION 3.30)
project(Fawry_Task)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fawry_Task
        main.cpp
        Property.cpp
        Product.cpp
        Customer.cpp
        Cart.cpp
        Services.cpp
)

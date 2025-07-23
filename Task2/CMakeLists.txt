cmake_minimum_required(VERSION 3.30)
project(Fawry_Task2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Fawry_Task2 main.cpp
        Book.h
        Book.cpp
        Book_types.h
        Book_types.cpp
        Quantum_book_store.h
        Quantum_book_store.cpp
        Quantum_book_store_testing.cpp
        Services.h
        Services.cpp
)

cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 99)

add_executable(food_ordering main.c food.h food.c addPreferences.h addPreferences.c order.h order.c input.h input.c)
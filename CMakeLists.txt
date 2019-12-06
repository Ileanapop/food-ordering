cmake_minimum_required(VERSION 3.15)
project(food_ordering C)

set(CMAKE_C_STANDARD 99)

add_executable(food_ordering main.c food.h food.c extraPreferences.h extraPreferences.c order.h order.c userIdentification.h userIdentification.c dataInput.h dataInput.c validationRules.h validationRules.c)
cmake_minimum_required(VERSION 3.27)
project(project)

set(CMAKE_CXX_STANDARD 17)

add_executable(project main.cpp
        Bot.cpp
        Bot.h
        SortBot.cpp
        SortBot.h
        DigBot.cpp
        DigBot.h
        Game.cpp
        Game.h
        SortBotDescending.cpp
        SortBotDescending.h
        Test.cpp
        Test.h)

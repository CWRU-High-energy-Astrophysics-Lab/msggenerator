cmake_minimum_required(VERSION 3.18)
project(msggenerator)

set(CMAKE_CXX_STANDARD 14)

add_executable(msggenerator main.cpp
        msg_outline/T2msg.cpp
        msg_outline/T2msg.h
        msg_outline/Generalmsg.cpp
        msg_outline/Generalmsg.h
        msg_outline/Logmsg.cpp
        msg_outline/Logmsg.h
        msg_outline/T3msg.cpp
        msg_outline/T3msg.h
        msg_outline/MsgHistory.cpp
        msg_outline/MsgHistory.h
        msg_outline/Cmdmsg.h
        msg_outline/Cmdmsg.cpp
        msg_outline/augermsg.h
        msg.h)

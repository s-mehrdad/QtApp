﻿
# ============================================================================
#/ <summary>
#/ CMakeLists.txt
#/ QtApp - libScreenshot
#/ created by Mehrdad Soleimanimajd on 03.10.2019
#/ </summary>
#/ <created>ʆϒʅ, 03.10.2019</created>
#/ <changed>ʆϒʅ, 27.06.2023</changed>
# ============================================================================

cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME libScreenshot)

set(PROJECT_NAME ${TARGET_NAME})

project(${PROJECT_NAME}
    VERSION 0.1.0.0
    DESCRIPTION "Qt ScreenshotWindow library"
    HOMEPAGE_URL "https://github.com/s-mehrdad/QtApp"
    LANGUAGES CXX
    )

set(CMAKE_INCLUDE_CURRENT_SOURCE_DIR ON)

list(APPEND HEADER_FILES
    screenshot.h
    )

list(APPEND SOURCE_FILES
    screenshot.cpp
    )

if(WIN32)
    #  list(APPEND SOURCE_FILES ${HEADER_FILES})
    #          list(APPEND SOURCE_FILES ${UI_FILES})
endif(WIN32)

add_library(${TARGET_NAME}
    ${SOURCE_FILES}
    ${HEADER_FILES}
    )

target_link_libraries(${TARGET_NAME}
    PUBLIC libStyle
    PUBLIC Qt6::Widgets
    )

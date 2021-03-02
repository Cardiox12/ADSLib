cmake_minimum_required(VERSION 3.17)
project(Ads)

set(CMAKE_CXX_STANDARD 17)

add_library(Ads
#        Sources
        srcs/AdsHandler.cpp
#        Headers
        includes/AdsHandler.h
        includes/AdsInfos.h
        externals/includes/TcAdsAPI.h
        externals/includes/TcAdsDef.h
        includes/AdsException.h)
target_link_libraries(Ads "${PROJECT_SOURCE_DIR}/externals/lib/TcAdsDll.lib")

add_executable(main
        #        Sources
        main.cpp
        #        Headers
        externals/includes/TcAdsAPI.h
        externals/includes/TcAdsDef.h
        includes/AdsHandler.h
        includes/AdsInfos.h
        includes/AdsException.h)
target_link_libraries(main Ads)
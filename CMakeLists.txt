cmake_minimum_required(VERSION 3.17)
project(Ads)

set(CMAKE_CXX_STANDARD 17)

add_library(Ads
#        Sources
        srcs/Ads.cpp
        externals/lib/TcAdsDll.lib
#        Headers
        includes/Ads.h
        includes/AdsInfos.h
        externals/includes/TcAdsAPI.h
        externals/includes/TcAdsDef.h
        )
add_executable(main srcs/Ads.cpp includes/Ads.h includes/AdsInfos.h main.cpp)
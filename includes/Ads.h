//
// Created by Cardi on 3/1/2021.
//

#ifndef ADS_ADS_H
#define ADS_ADS_H

#include "AdsInfos.h"
#include <iostream>

class AdsInterface {
    unsigned long   m_handle;
    AdsInfos        m_connector;
public:
    AdsInterface(){
        std::cout << "Hello from AdsInterface" << std::endl;
    };
};


#endif //ADS_ADS_H

//
// Created by Cardi on 3/1/2021.
//

#ifndef ADS_INFOS_H
#define ADS_INFOS_H

#include "../externals/includes/TcAdsDef.h"

struct AdsInfos {
    long        error;
    long        port;
    AmsAddr     addr;
    PAmsAddr    pAddr;
};

#endif //ADS_INFOS_H

//
// Created by Cardi on 3/1/2021.
//

#include "includes/AdsHandler.h"

int     main()
{
//    Naming convention for ADS Variables is PLC_PROG_NAME.PLC_VARNAME
    AdsHandler<bool> inHandle{ "MAIN.In" };
    AdsHandler<bool> outHandle{ "MAIN.Out" };

    inHandle.connect();
    outHandle.connect();
    return (0);
}
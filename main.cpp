//
// Created by Cardi on 3/1/2021.
//

#include "includes/AdsHandler.h"

int     main()
{
    AdsHandler<bool> handle{ "In" };

    handle.connect();
    return (0);
}
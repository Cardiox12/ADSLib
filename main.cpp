//
// Created by Cardi on 3/1/2021.
//

#include "includes/AdsHandler.h"
#include <string>

int     main()
{
    AdsHandler<bool[2]> inHandle{ "MAIN.pressure" };
    bool *pressure = new bool[2];

    try {
        inHandle.connect();


        memcpy(pressure, inHandle.read(), sizeof(bool) * 2);

        std::cout << "In : (" << pressure[0] << "," << pressure[1] << ")" << std::endl;

        pressure[0] = true;
        pressure[1] = false;

        std::cout << "Out : (" << pressure[0] << "," << pressure[1] << ")" << std::endl;

        inHandle.write(pressure, 2);

    } catch (std::exception &error){
        std::cout << error.what() << std::endl;
    }

    delete[] pressure;
    return (0);
}
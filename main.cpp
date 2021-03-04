//
// Created by Cardi on 3/1/2021.
//

#include "includes/AdsHandler.h"

int     main()
{
    AdsHandler<bool> inHandle{ "MAIN.In" };
    AdsHandler<bool> outHandle{ "MAIN.Out" };

    try {
        inHandle.connect();
        outHandle.connect();

        std::cout << "In : " << inHandle.read() << std::endl;
        std::cout << "Out : " << outHandle.read() << std::endl;

        inHandle.write(true);
        outHandle.write(true);
    } catch (std::exception &error){
        std::cout << error.what() << std::endl;
    }

    return (0);
}
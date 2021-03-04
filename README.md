# AdsLib

This project aims to create a facade for TC-ADS from Beckhoff and make it compatible with C++.
The library use template to create generic handlers, that makes easy to create handlers.

### Example

AdsLib makes ADS connection easy in C++.
```c++
// Declare the handler, naming convention for PLC variables are
// prog_name.var_name
AdsHandler<bool> inHandle{ "MAIN.In" };

try {
//  We connect to TwinCat3 
    inHandle.connect();

//    Reading variable from TwinCat3
    std::cout << "In : " << inHandle.read() << std::endl;

//    Write variable to TwinCat3
    inHandle.write(true);
    
//  Catch potential errors,
//  ConnectionFailed, HandleFailed, ReadFailed, WriteFailed ...  
} catch (std::exception &error){
    std::cout << error.what() << std::endl;
}
```
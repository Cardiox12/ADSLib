//
// Created by Cardi on 3/1/2021.
//

#ifndef ADS_HANDLER_H
#define ADS_HANDLER_H

#include "../externals/includes/TcAdsAPI.h"
#include "../includes/AdsHandler.h"
#include "AdsException.h"
#include "AdsInfos.h"
#include <iostream>
#include <string>

template<typename T>
class AdsHandler {
    unsigned long   m_handle;
    AdsInfos        m_connect{};
    T               m_data;
    std::string     m_varname;
public:
    AdsHandler(std::string varname) : m_varname{ varname } {};

    void    connect();
    void    write(T data, size_t size);
    T       &read();
};

template<typename T>
void AdsHandler<T>::connect(){
    m_connect.pAddr = &m_connect.addr;
    m_connect.port = AdsPortOpen();

    if ( AdsGetLocalAddress(m_connect.pAddr) ){
        throw AdsConnectionFailed("failed to connect to TwinCat3");
    }

    m_connect.pAddr->port = AMSPORT_R0_PLC_TC3;

//  Get handle by name
//  The naming convention for ADS Variables are Prog.Varname
    if ( AdsSyncReadWriteReq( m_connect.pAddr, ADSIGRP_SYM_HNDBYNAME, 0x0, sizeof( m_handle ), &m_handle,
                              m_varname.size(), (void*)(m_varname.c_str()) ) ){
        throw AdsHandleFailed("failed to handle variable");
    }
}

template<typename T>
T &AdsHandler<T>::read() {

    if ( AdsSyncReadReq( m_connect.pAddr, ADSIGRP_SYM_VALBYHND, m_handle, sizeof( m_data ), &m_data ) ){
        throw AdsReadFailed("reading variable from TwinCat3 failed");
    }

    return (m_data);
}

template<typename T>
void AdsHandler<T>::write(T data, size_t size) {
    if ( AdsSyncWriteReq( m_connect.pAddr, ADSIGRP_SYM_VALBYHND, m_handle, size, data) ){
        throw AdsWriteFailed("writing variable to TwinCAT3 failed");
    }
}

#endif //ADS_HANDLER_H

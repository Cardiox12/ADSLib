//
// Created by Cardi on 3/2/2021.
//

#ifndef ADS_EXCEPTION_H
#define ADS_EXCEPTION_H

#include <exception>
#include <iostream>

class AdsConnectionFailed : public std::exception {
    std::string m_message;
public:
    explicit AdsConnectionFailed(const std::string &message){
        m_message = message;
        std::cerr << "AdsConnectionFailed: " << message << std::endl;
    };

    [[nodiscard]] const char *what() const noexcept override {
        std::cout << "AdsConnectionFailed: " << m_message << std::endl;
        return (m_message.c_str());
    }
};

class AdsHandleFailed : public std::exception {
    std::string m_message;
public:
    explicit AdsHandleFailed(const std::string &message){
        m_message = message;
        std::cerr << "AdsHandleFailed: " << message << std::endl;
    };

    [[nodiscard]] const char *what() const noexcept override {
        std::cout << "AdsHandleFailed: " << m_message << std::endl;
        return (m_message.c_str());
    }
};

class AdsReadFailed : public std::exception {
    std::string m_message;
public:
    explicit AdsReadFailed(const std::string &message){
        m_message = message;
        std::cerr << "AdsReadFailed: " << message << std::endl;
    };

    [[nodiscard]] const char *what() const noexcept override {
        std::cout << "AdsReadFailed: " << m_message << std::endl;
        return (m_message.c_str());
    }
};

#endif //ADS_EXCEPTION_H

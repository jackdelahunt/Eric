#pragma once
#include <exception>

struct EricException : public std::exception {
public:
    const char* message;

    EricException(const char* message) {
        this->message = message;
    }

    const char * what () const throw () {
        return message;
    }
};

#define THROW(message) \
    throw EricException(message);

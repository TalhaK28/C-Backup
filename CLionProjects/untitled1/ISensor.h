//
// Created by talha on 10/11/2024.
//

#ifndef ISENSOR_H
#define ISENSOR_H

#include <string>

class ISensor {
public:
    virtual ~ISensor() = default;
    virtual void update() = 0;
    virtual std::string getType() const = 0;
};



#endif ISENSOR_H

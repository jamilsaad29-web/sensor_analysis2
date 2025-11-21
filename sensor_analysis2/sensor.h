#pragma once
#include <string>
using namespace std;

// Abstract base class for all sensors
class Sensor {
public:
    virtual ~Sensor() = default;         // Virtual destructor for safe deletion
    virtual double read() = 0;           // Pure virtual method to read sensor
    virtual string name() const = 0;     // Return sensor name
    virtual string unit() const = 0;     // Return sensor unit
};


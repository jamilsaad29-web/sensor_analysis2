#pragma once
#include <string>
using namespace std;

// Struct for sensor measurement
struct Measurement {
    string sensorName;   // Name of sensor
    string unit;         // Unit of measurement
    double value;        // Measured value
    string timestamp;    // Timestamp of measurement
};


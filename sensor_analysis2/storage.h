#pragma once
#include <vector>
#include <string>
#include "measurement.h"
using namespace std;

// Class to store measurements
class MeasurementStorage {
private:
    vector<Measurement> dataList;   // Vector to store all measurements
public:
    void addMeasurement(Measurement m);
    void printAll() const;
    void printStatistics(string sensorName) const;
    void saveToFile(string filename) const;
    void loadFromFile(string filename);
    void printHistogram(string sensorName) const;
}; // Class for measurement storage and analysis



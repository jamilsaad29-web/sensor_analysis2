#pragma once
#include <vector>
#include <memory>
#include <string>
#include "sensor.h"
#include "storage.h"
using namespace std;

// Structure for threshold alerts
struct Threshold {
    string sensorName;
    double limit;
    bool over; 
    string timestamp;
    double value;
};

class SystemController {
private:
    vector<unique_ptr<Sensor>> sensors_;   // Polymorphic sensors
    MeasurementStorage storage_;           // Storage of measurements
    vector<Threshold> thresholds_;        // Threshold rules
public:
    void addSensor(unique_ptr<Sensor> s) { sensors_.push_back(move(s)); }
    void sampleAllOnce();
    void configureThreshold();
    void showAlerts() const;
    void showStatsFor(const string& sensorName) const { storage_.printStatistics(sensorName); }
    void saveToFile(const string& path) const { storage_.saveToFile(path); }
    void loadFromFile(const string& path) { storage_.loadFromFile(path); }
    void printAll() const { storage_.printAll(); }
    void printHistogram(const string& sensorName) const { storage_.printHistogram(sensorName); }
}; // System controller managing sensors and storage


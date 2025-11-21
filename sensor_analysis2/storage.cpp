#include "storage.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;

void MeasurementStorage::addMeasurement(Measurement m) {
    dataList.push_back(m); // Add measurement to vector
}

void MeasurementStorage::printAll() const {
    cout << "\nAll Measurements:\n";
    for (auto m : dataList) {
        cout << m.timestamp << ", " << m.sensorName << ", "
			<< fixed << setprecision(2) << m.value << ", " << m.unit << endl; // Print each measurement
    }
} // Print all stored measurements

void MeasurementStorage::printStatistics(string sensorName) const {
    vector<double> values;
    for (auto m : dataList)
        if (m.sensorName == sensorName)
            values.push_back(m.value);

	if (values.empty()) { cout << "No measurements for " << sensorName << ".\n"; return; } // No data check

    double sum = 0;
    for (double v : values) sum += v;
    double avg = sum / values.size();
    double minV = *min_element(values.begin(), values.end());
	double maxV = *max_element(values.begin(), values.end()); // Calculate standard deviation

    double variance = 0;
    for (double v : values) variance += pow(v - avg, 2);
    variance /= values.size();
    double stdDev = sqrt(variance);

    cout << "\nStatistics for " << sensorName << ":\n";
    cout << "Number of readings: " << values.size() << endl;
    cout << "Average: " << fixed << setprecision(2) << avg << endl;
    cout << "Min: " << minV << endl;
    cout << "Max: " << maxV << endl;
	cout << "Standard deviation: " << stdDev << endl; 
} // Print statistics for a specific sensor

void MeasurementStorage::saveToFile(string filename) const {
    ofstream file(filename);
    if (!file) { cout << "Could not open file for writing.\n"; return; }

    for (auto m : dataList)
        file << m.timestamp << ", " << m.sensorName << ", " << m.value << ", " << m.unit << "\n";

    cout << "Data saved to file: " << filename << endl;
} // Save measurements to file

void MeasurementStorage::loadFromFile(string filename) {
    ifstream file(filename);
    if (!file) { cout << "Could not open file for reading.\n"; return; }

    string timestamp, name, unit;
    double value;
    while (file >> timestamp >> name >> value >> unit) {
        Measurement m = { name, unit, value, timestamp };
        dataList.push_back(m);
    }
    cout << "Data loaded from file.\n";
} // Load measurements from file

void MeasurementStorage::printHistogram(string sensorName) const {
    vector<double> values;
    for (auto m : dataList)
        if (m.sensorName == sensorName)
            values.push_back(m.value);

    if (values.empty()) { cout << "No measurements for " << sensorName << ".\n"; return; }

    cout << "\nASCII Histogram for sensor: " << sensorName << endl;
    sort(values.begin(), values.end());
    double minV = values.front();
    double maxV = values.back();
    double step = 0.5;

    for (double start = minV; start <= maxV; start += step) {
        double end = start + step;
        int count = 0;
        for (double v : values)
            if (v >= start && v < end) count++;
        if (count > 0) {
            cout << fixed << setprecision(1);
            cout << setw(6) << start << " - " << setw(5) << end << " | ";
            for (int i = 0; i < count; ++i) cout << "*";
            cout << endl;
        }
    }
    cout << "\nEach * represents one measurement in that range.\n";
} // Print ASCII histogram for a specific sensor

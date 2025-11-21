#pragma once
#include "sensor.h"
#include <string>
#include <random>
using namespace std;

class TemperatureSensor : public Sensor {
private:
    string id_;
    double minV_, maxV_;
    random_device rd_;
    mt19937 gen_;
public:
    TemperatureSensor(string id, double minV, double maxV)
        : id_(id), minV_(minV), maxV_(maxV), gen_(rd_()) {
	} // Constructor initializing sensor ID and value range

    double read() override {
        uniform_real_distribution<> dist(minV_, maxV_);
        return dist(gen_);
    }
    string name() const override { return id_; }
    string unit() const override { return "°C"; }
}; // Temperature sensor class



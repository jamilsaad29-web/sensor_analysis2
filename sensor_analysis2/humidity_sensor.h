#pragma once
#include "sensor.h"
#include <string>
#include <random>
using namespace std;

class HumiditySensor : public Sensor {
private:
    string id_;
    double minV_, maxV_;
    random_device rd_;
    mt19937 gen_;
public:
    HumiditySensor(string id, double minV, double maxV) 
        : id_(id), minV_(minV), maxV_(maxV), gen_(rd_()) { 
    }

    double read() override {
		uniform_real_distribution<> dist(minV_, maxV_);  // Generate random humidity value
        return dist(gen_);
    }
	string name() const override { return id_; } // Return sensor ID
	string unit() const override { return "%"; } // Humidity unit
};


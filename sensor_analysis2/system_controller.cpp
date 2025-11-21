#include "system_controller.h"
#include "utils.h"
#include <iostream>
using namespace std;

void SystemController::sampleAllOnce() {
    for (auto& s : sensors_) {
        double val = s->read();          // Get sensor value
        string ts = currentTime();       // Get current timestamp
        Measurement m = { s->name(), s->unit(), val, ts };
        storage_.addMeasurement(m);      // Store measurement

        // Check threshold alerts
        for (auto& t : thresholds_) {
            if (t.sensorName == s->name()) {
                if ((t.over && val > t.limit) || (!t.over && val < t.limit)) {
                    t.value = val;
                    t.timestamp = ts;
                    cout << "ALERT! " << s->name() << " value " << val
                        << " " << s->unit() << " at " << ts << endl;
                }
            }
        }
    }
}

void SystemController::configureThreshold() {
    cout << "Enter sensor name for threshold: ";
    string name; cin >> name;
    cout << "Enter limit value: ";
    double limit; cin >> limit;
    cout << "Alert when over? (1 = yes, 0 = no): ";
    bool over; cin >> over;

    Threshold t = { name, limit, over, "", 0 };
    thresholds_.push_back(t);

    cout << "Threshold configured for " << name << endl;
} // Configure a new threshold alert

void SystemController::showAlerts() const {
    cout << "\n--- Active Alerts ---\n";
    for (auto& t : thresholds_) {
        if (t.timestamp != "") {
            cout << t.timestamp << " - " << t.sensorName << " value "
                << t.value << " triggered threshold "
                << (t.over ? "over" : "under") << " " << t.limit << endl;
        }
    }
} // Show all active alerts

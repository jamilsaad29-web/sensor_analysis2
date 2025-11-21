#include "system_controller.h"
#include "temperature_sensor.h"
#include "humidity_sensor.h"    // sub
#include "pressure_sensor.h"
#include <memory>  // &
#include <iostream>
using namespace std;

int main() {
    SystemController controller;

    // Add sensors to controller
    controller.addSensor(make_unique<TemperatureSensor>("Temp1", 20.0, 25.0));
    controller.addSensor(make_unique<HumiditySensor>("Hum1", 40.0, 60.0));
    controller.addSensor(make_unique<PressureSensor>("Press1", 950.0, 1050.0));

// Display menu
    int choice = 0;
    while (choice != 8) {
        
        cout << "\n===== MENU =====\n";
        cout << "1. Read new sensor values\n";
        cout << "2. Show statistics per sensor\n";
        cout << "3. Show all measurements\n";
        cout << "4. Configure threshold\n";
        cout << "5. Show alerts\n";
        cout << "6. Show ASCII histogram\n";
        cout << "7. Save to file\n";
        cout << "8. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1) controller.sampleAllOnce();
        else if (choice == 2) {
            cout << "Enter sensor name: ";
            string name; cin >> name;
            controller.showStatsFor(name);
        }
        else if (choice == 3) controller.printAll();
        else if (choice == 4) controller.configureThreshold();
        else if (choice == 5) controller.showAlerts();
        else if (choice == 6) {
            cout << "Enter sensor name: ";
            string name; cin >> name;
            controller.printHistogram(name);
        }
        else if (choice == 7) controller.saveToFile("data.txt");
        else if (choice == 8) cout << "Exiting program...\n";
        else cout << "Invalid option.\n";
    }

    return 0;
}

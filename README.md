# sensor_analysis2
README – Sensorövervakningssystem

Detta projekt är ett sensorövervakningssystem som simulerar tre olika sensorer: temperatur, luftfuktighet och lufttryck. Varje sensor genererar slumpmässiga värden inom ett bestämt intervall. Programmet kan samla in mätningar, visa statistik, visa histogram, hantera larm och spara data till en fil.

Projektstruktur:
main.cpp
sensor.h
sensor.cpp
temperature_sensor.h
temperature_sensor.cpp
humidity_sensor.h
humidity_sensor.cpp
pressure_sensor.h
pressure_sensor.cpp
measurement.h
measurement.cpp
storage.h
storage.cpp
system_controller.h
system_controller.cpp

Översikt av systemet:
Sensor är en basklass som de tre sensorsorterna ärver ifrån. Varje sensor måste implementera funktionerna read, name och unit. TemperatureSensor, HumiditySensor och PressureSensor använder slumpgenerering för att skapa värden.

Measurement representerar en enskild mätning med namn, värde och tidsstämpel. MeasurementStorage ansvarar för att lagra, skriva ut och analysera alla mätningar. Den kan även skapa histogram och hantera sparning till fil.

SystemController håller ihop programmet genom att hantera sensorerna, mätningarna, tröskelvärden och larm. main.cpp visar menyvalen och låter användaren styra programmet.

Kompilering:
g++ -std=c++17 main.cpp system_controller.cpp storage.cpp sensor.cpp temperature_sensor.cpp humidity_sensor.cpp pressure_sensor.cpp measurement.cpp -o sensorsystem

Körning:
./sensorsystem

Menyval:
1: Ta nya sensorvärden
2: Visa statistik för en sensor
3: Visa alla mätningar
4: Ställa in tröskelvärde för larm
5: Visa aktiverade larm
6: Visa ASCII-histogram
7: Spara mätningar till fil
8: Avsluta programmet

Kort beskrivning av vad programmet gör:
Programmet läser av mätvärden från flera sensorer som simuleras. Resultaten sparas och kan analyseras på olika sätt. Användaren kan se statistik, hitta värden som bryter mot tröskelvärden, skriva ut mätvärden i histogram och lagra datan i en fil.

Viktiga programmeringsbegrepp:
Arv används eftersom alla sensorer bygger på samma basklass. Polymorfism används när sensorerna lagras i en vektor av pekare till basklassen, vilket gör att olika sensortyper kan behandlas på samma sätt. Datastrukturer som används är vector för att lagra mätningar och sensorer, map för tröskelvärden och mindre vektorer för statistik och histogram.

Projektet visar grundläggande objektorientering, filhantering, slumpgenerering och menyhantering i C++.


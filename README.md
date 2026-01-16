# Esp32_SmartThermometer
An IoT-driven environmental control system that monitors and manages room humidity via a mobile application.

This project is an upgraded version of the ESP32_Thermometer repository. By leveraging the power of IoT, it enables users to monitor and control their environment remotely from any Wi-Fi-enabled device. The system utilizes a DHT11 sensor for data acquisition and the Blynk IoT Cloud for seamless connectivity and real-time interface management.

* Real-time Monitoring: Users can track live temperature and humidity data through a sleek mobile dashboard. This ensures constant environmental awareness regardless of the user's location.

* Dynamic Threshold Control: Unlike static systems, this project allows users to adjust the humidity threshold dynamically. By simply moving a slider widget on their smartphone, users can define the exact point at which the system triggers an alert or visual indicator.

* Multi-Platform Accessibility: The system is not limited to mobile devices. Users can also manage threshold values and view environmental data through a comprehensive web dashboard, ensuring a unified experience across all platforms.



![smartThermo1](https://github.com/user-attachments/assets/7563d057-d38f-438d-b984-63f8a62ce58a)
The dashboard displays live environmental metrics, providing immediate insights into the room's conditions.

![smartThermo2](https://github.com/user-attachments/assets/f23411fa-d25d-4ead-b837-9a828307a120)
The slider widget enables the user to calibrate the humidity threshold with ease.


![smartThermo3](https://github.com/user-attachments/assets/8ad2696f-af9b-4497-ab0c-08d88d0d1466)
Monitoring and controlling the system via a browser, showcasing the cloud-based flexibility of the project.



Technical Info of:

Hardware: ESP32, DHT11 Sensor, LEDs.
Protocol: MQTT / Blynk Cloud.
Software: C++ (Arduino IDE), Blynk Mobile App & Console.

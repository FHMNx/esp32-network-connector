# ESP32 Network Connector

A foundational ESP32 boilerplate for establishing WiFi connections using the Arduino core.

## ESP32 DevKit V1 Reference Diagram

Below is the standard pinout for the 30-pin ESP32 WROOM-32 development board for hardware wiring reference.

```text
                             +-----------------------+
                             |      |  [USB]  |      |
                             |      +---------+      |
                             |   [ ] BOOT   EN [ ]   |
                             |                       |
                     EN  - - | 1                   30| - - D23  (VSPI MOSI)
   (Input Only)      VP  - - | 2                   29| - - D22  (I2C SCL)
   (Input Only)      VN  - - | 3      +---------+  28| - - TX0  (UART TX)
   (Input Only)      D34 - - | 4      |         |  27| - - RX0  (UART RX)
   (Input Only)      D35 - - | 5      |  ESP32  |  26| - - D21  (I2C SDA)
   (Touch / ADC)     D32 - - | 6      |  WROOM  |  25| - - D19  (VSPI MISO)
   (Touch / ADC)     D33 - - | 7      |  32     |  24| - - D18  (VSPI CLK)
   (DAC 1 / ADC)     D25 - - | 8      |         |  23| - - D5   (VSPI CS)
   (DAC 2 / ADC)     D26 - - | 9      +---------+  22| - - TX2
   (Touch / ADC)     D27 - - | 10                  21| - - RX2
   (Touch / ADC)     D14 - - | 11                  20| - - D4   (ADC2 / Touch)
   (Touch / ADC)     D12 - - | 12  [ ]             19| - - D2   (ADC2 / Touch)
   (Touch / ADC)     D13 - - | 13  LED             18| - - D15  (ADC2 / Touch)
                     GND - - | 14                  17| - - GND
               (5V)  VIN - - | 15                  16| - - 3V3  (3.3V)
                             +-----------------------+
                                 Wi-Fi & Bluetooth

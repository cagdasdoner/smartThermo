Arduino Setup for ESP8266 :

    1. Install the Arduino IDE 1.6.4 or greater from : https://www.arduino.cc/en/Main/Software
    2. To Install the ESP8266 Board Package, go to : File->Preferences from menu.
    3. Add http://arduino.esp8266.com/stable/package_esp8266com_index.json to Additional Boards Manager URLs.
    4. Go to Boards Manager from Tools->Board->Boards Manager.
    5. Search for esp8266 and install.
    6. Now you are able to select esp8266 as a board from Tools->Board.
    7. Select "NodeMCU 1.0" as board, 80 MHz as CPU Frequency, 4M (1M SPIFFS) as Flash Size.
    8. To be able to write SW on device and get traces, connect NodeMCU to the USB port of the PC and select a proper device path from Tools->Port menu of the Arduino IDE.
    9. For linux users, add your user to the group of dialout to enable serial comm.

NOTE: Please be sure that you are able to upload software to the connected device.

NOTE: We will need PubSubClient library for the workshop. To install arduino libraries use Sketch->Include Libraries->Library Manager or Add .ZIP Library.

PubSubClient : https://github.com/knolleary/pubsubclient/

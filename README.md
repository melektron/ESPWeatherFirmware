# ESP Weatherstation Firmware

## Build
In case you want to build your own weather station, you need to add an extra file to the code:

**_src/wserver/secrets.h_**
```cpp
#define STATION_ID <station id>
#define STATION_SECRET "\"<homedb api token>\""

#define SSID "<WiFi SSID>"
#define PWD "<WiFi Password>"
```
Everything in `<>` brackets needs to be replaced with your own data.

#ifndef EDDYSTONE_H_
#define EDDYSTONE_H_
#endif

#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <BLEDevice.h>

class Eddystone{
    public:
        Eddystone(std::string uuid, std::string prefix, std::string url, std::string suffix, std::string parameter);
        static char findVectorIndex(std::vector<std::string> &vector, std::string find);
        static std::string generateUrl(std::string prefix, std::string url, std::string suffix, std::string parameter);

        virtual ~Eddystone(){};

    private:
        BLEServer *server;
        BLEService *service;
        BLECharacteristic *characteristic;
        BLEAdvertising *advertising;
        BLEAdvertisementData advData;

        std::string _uuid;
        std::string _encodeddata;
};
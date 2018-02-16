#include "Eddystone.h"
#include "esp_log.h"

// TODO setup in header file
// https://github.com/google/eddystone/tree/master/eddystone-url#eddystone-url-http-url-encoding
std::vector<std::string> prefixVector{
    "http://www.",
    "https://www.",
    "http://",
    "https://",
    "urn:uuid:"
};

// TODO: IMPORTANT: Why does .com/ not work?
std::vector<std::string> suffixVector{
    ".com/",
    ".org/",
    ".edu/",
    ".net/",
    ".info/",
    ".biz/",
    ".gov/",
    ".com",
    ".org",
    ".edu",
    ".net",
    ".info",
    ".biz",
    ".gov"
};

Eddystone::Eddystone(std::string uuid, std::string prefix, std::string url, std::string suffix, std::string parameter){
    _uuid = uuid;
    _encodeddata = Eddystone::generateUrl(prefix, url, suffix, parameter);

    BLEDevice::init("Eddystone");
    server = BLEDevice::createServer();
    service = server->createService(uuid);
    service->start();

    advertising = server->getAdvertising();
    advData.setFlags(ESP_BLE_ADV_FLAG_GEN_DISC | ESP_BLE_ADV_FLAG_BREDR_NOT_SPT);
    advData.setCompleteServices(uint16_t(0xFEAA));
    advData.setServiceData((BLEUUID)((uint16_t)0xFEAA), _encodeddata.c_str());
    advertising->setAdvertisementData(advData);
    advertising->start();
}

// TODO: Create Validate() function that checks incoming communication from wifi or bluetooth
// Validate through that function, if it's false don't run this function
std::string Eddystone::generateUrl(std::string prefix, std::string url, std::string suffix, std::string parameter){
    std::string encoded = "";
	encoded += (char)0x10;
    // Should be TX power, needs research (what values can I give this, to reduce or increase the power)
    // This can be found at https://github.com/google/eddystone/tree/master/eddystone-url
	encoded += (char)0x20;

    if(prefix != ""){
        encoded += Eddystone::findVectorIndex(prefixVector, prefix);
    }

    encoded += url;

    if(suffix != ""){
        encoded += Eddystone::findVectorIndex(suffixVector, suffix);
    }

    encoded += parameter;

    if(encoded.length() > 17){
        ESP_LOGI("beacon", "Encoded value as string exceeds the 17 charactar limit: %s", encoded.c_str());
    } else {
        ESP_LOGI("beacon", "Encoded value as string: %s", encoded.c_str());
    }
    return encoded;
}

// TODO: implement something in generateUrl that recognizes the return -1
// If this function returns -1 it's an invalid value, and shouldn't be trusted
char Eddystone::findVectorIndex(std::vector<std::string> &vector, std::string find){
    auto result = std::find(std::begin(vector), std::end(vector), find);
    if (result != std::end(vector)) {
        return std::distance(vector.begin(), result);
    }
    ESP_LOGE("beacon", "FAILED CREATING URL, WILL BE UNUSABLE (findVectorIndex didn't find a valid pre- or suffix")
    return -1;
}
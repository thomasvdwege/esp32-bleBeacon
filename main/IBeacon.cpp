// TODO: iBeacon implementation

// Two iBeacon examples, not tested with an iDevice, but sometimes Android labels it as an iBeacon

// BLEAdvertising* pAdvertising = setting->getAdvertising();
// BLEAdvertisementData advertisementData;
// advertisementData.setName("MyName");
// advertisementData.setFlags(ESP_BLE_ADV_FLAG_LIMIT_DISC | ESP_BLE_ADV_FLAG_GEN_DISC | ESP_BLE_ADV_FLAG_BREDR_NOT_SPT);
// advertisementData.setPartialServices(BLEUUID("4fafc200-1fb5-459e-8fcc-c5c9c331914b"));
// pAdvertising->setAdvertisementData(advertisementData);
// pAdvertising->setScanResponseData(advertisementData);
// pAdvertising->start();

//   BLEBeacon myBeacon;
//   myBeacon.setManufacturerId(4321);
//   myBeacon.setMajor(5);
//   myBeacon.setMinor(88);
//   myBeacon.setProximityUUID(BLEUUID(UUID_SERVICE));
//   myBeacon.setSignalPower(99);
//   myBeacon.setData("google.com");

//   BLEAdvertisementData advertisementData;
//   advertisementData.setFlags(ESP_BLE_ADV_FLAG_LIMIT_DISC | ESP_BLE_ADV_FLAG_GEN_DISC | ESP_BLE_ADV_FLAG_BREDR_NOT_SPT);
//   advertisementData.setManufacturerData(myBeacon.getData());

//   BLEAdvertising* pAdvertising = setting->getAdvertising();
//   pAdvertising->setAdvertisementData(advertisementData);
//   pAdvertising->setScanResponseData(advertisementData);
//   pAdvertising->start();
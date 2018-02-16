#include "Eddystone.h"
#include <rom/ets_sys.h>
#include "esp_log.h"

extern "C" {
	void app_main(void);
}

void app_main(void) {
	//TODO: Create random UUID
	//TODO: Check if the bluetooth module is in use, if it is, cancel the creation of the beacon object
	//TODO: IMPORTANT: Why does .com/ inside suffixvector not work?

	ESP_LOGI("beacon", "Starting beacon");
	// Below doesn't work because ".com/" is not recognized for some reason
	// Eddystone *beacon = new Eddystone("78489c82-5e4c-4c0b-b3ca-54390af7bf8c", "https://", "github", ".com/", "");
	Eddystone *beacon = new Eddystone("78489c82-5e4c-4c0b-b3ca-54390af7bf8c", "https://", "goo.gl/g6v1dQ", "", "");
}

// TODO: Create the beacon on one core. In the future, the other core could be utilizited for setup.

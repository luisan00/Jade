// tdisplays3 and devices with no power-management but it can measure voltage level of the battery and
// detect charging status when a battery is connected through an analog input
//

esp_err_t power_init(void) { return ESP_OK; }
esp_err_t power_shutdown(void) { return ESP_OK; }
esp_err_t power_screen_on(void) { return ESP_OK; }
esp_err_t power_backlight_on(const uint8_t brightness) { return ESP_OK; }
esp_err_t power_backlight_off(void) { return ESP_OK; }
esp_err_t power_camera_on(void) { return ESP_OK; }
esp_err_t power_camera_off(void) { return ESP_OK; }
uint16_t power_get_vbat(void) { return 0; }
uint8_t power_get_battery_status(void) { return 0; }
bool power_get_battery_charging(void) { return false; }
uint16_t power_get_ibat_charge(void) { return 0; }
uint16_t power_get_ibat_discharge(void) { return 0; }
uint16_t power_get_vusb(void) { return 0; }
uint16_t power_get_iusb(void) { return 0; }
uint16_t power_get_temp(void) { return 0; }
bool usb_connected(void) { return false; }
void enable_usb_host(void) { (void)0; };
void disable_usb_host(void) { (void)0; };

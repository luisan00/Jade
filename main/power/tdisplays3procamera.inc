// tdisplays3 pro has SY6970:
// - Single Cell Li-Ion DC/DC Switching Charger with I2C Control
// - USB Detection
// - OTG JEITA Compliant,
// - Power Path Management
#include "power/i2c.inc"

#define SY6970_ADDR 0x6A
static i2c_master_dev_handle_t sy6970 = NULL;

esp_err_t power_init(void)
{
    //I2C_CHECK_RET(_power_i2c_init());
    //I2C_CHECK_RET(_power_i2c_attach_device(SY6970_ADDR, &sy6970));
    return ESP_OK;
}

esp_err_t power_shutdown(void) { return ESP_OK; }
esp_err_t power_screen_on(void) { return ESP_OK; }
esp_err_t power_backlight_on(const uint8_t brightness) { return ESP_OK; }
esp_err_t power_backlight_off(void) { return ESP_OK; }
esp_err_t power_camera_on(void) { return ESP_OK; }
esp_err_t power_camera_off(void) { return ESP_OK; }
uint16_t power_get_vbat(void)
{

    uint8_t buf = 0;
    //JADE_SEMAPHORE_TAKE(i2c_mutex);
    // I2C_LOG_ANY_ERROR(_power_master_read_slave(sy6970, 0x78, &buf, 1));
    //JADE_SEMAPHORE_GIVE(i2c_mutex);
    const uint16_t vbat = 4000 * 1.1;
    return vbat;
}
uint8_t power_get_battery_status(void)
{
    const uint16_t vbat = power_get_vbat();
    if (vbat > 4000) {
        return 5;
    } else if (vbat > 3850) {
        return 4;
    } else if (vbat > 3700) {
        return 3;
    } else if (vbat > 3550) {
        return 2;
    } else if (vbat > 3400) {
        return 1;
    }
    return 0;
}
bool power_get_battery_charging(void) { return true; }
uint16_t power_get_ibat_charge(void) { return 0; }
uint16_t power_get_ibat_discharge(void) { return 0; }
uint16_t power_get_vusb(void) { return 0; }
uint16_t power_get_iusb(void) { return 0; }
uint16_t power_get_temp(void) { return 0; }
bool usb_connected(void)
{
    uint8_t buf = 1;
    //JADE_SEMAPHORE_TAKE(i2c_mutex);
    // I2C_LOG_ANY_ERROR(_power_master_read_slave(sy6970, 0x00, &buf, 1));
    //JADE_SEMAPHORE_GIVE(i2c_mutex);

    const bool is_usb_connected = buf & 0b10000000;
    return is_usb_connected;
}
void enable_usb_host(void) { (void)0; };
void disable_usb_host(void) { (void)0; };

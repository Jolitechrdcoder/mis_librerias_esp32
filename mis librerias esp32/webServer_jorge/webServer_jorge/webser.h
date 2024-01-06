#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_mac.h"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "nvs_flash.h"
#include <lwip/api.h>
#include <esp_http_server.h>
#include "esp_mac.h"
#include "lwip/err.h"
#include "lwip/sys.h"
#include"AP_Jorge/ap_jorge.h"

httpd_handle_t configurar_servidor(void);
#include"webServer_jorge/webser.h"
#include"webServer_jorge/web.h"
char ssid_value[64] = "";
char password_value[64] = "";
static const char *TAG = "wifi softAP";
esp_err_t send_web_page(httpd_req_t *req)
{
    httpd_resp_send(req, formulario, strlen(formulario));
    return ESP_OK;
}

esp_err_t submit_handler(httpd_req_t *req)
{
    if (req->method == HTTP_POST)
    {
        char ssid_value[64] = "";
        char password_value[64] = "";

        // Increase the buffer size to accommodate larger POST requests
        char content[512];
        int content_len = httpd_req_recv(req, content, sizeof(content) - 1);
        content[content_len] = '\0';

        char *ssid_start = strstr(content, "ssid=");
        char *password_start = strstr(content, "password=");

        if (ssid_start && password_start)
        {
            sscanf(ssid_start, "ssid=%63s", ssid_value);
            sscanf(password_start, "password=%63s", password_value);

            ESP_LOGI(TAG, "SSID enviado: %s, Contraseña: %s", ssid_value, password_value);

            // Add your logic to handle the SSID and password values as needed.
        }
    }

    httpd_resp_set_status(req, "303 See Other");
    httpd_resp_set_hdr(req, "Location", "/");
    httpd_resp_send(req, NULL, 0);

    return ESP_OK;
}

httpd_uri_t uri_get = {
    .uri = "/",
    .method = HTTP_GET,
    .handler = send_web_page,
    .user_ctx = NULL
};

httpd_uri_t uri_submit = {
    .uri = "/submit",
    .method = HTTP_POST,
    .handler = submit_handler,
    .user_ctx = NULL
};

httpd_handle_t configurar_servidor(void)
{
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    httpd_handle_t server = NULL;

    if (httpd_start(&server, &config) == ESP_OK)
    {
        httpd_register_uri_handler(server, &uri_get);
        httpd_register_uri_handler(server, &uri_submit);
    }

    return server;
}
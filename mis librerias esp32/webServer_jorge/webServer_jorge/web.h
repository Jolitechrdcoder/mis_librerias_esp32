#include"webServer_jorge/webser.h"
char formulario[] = "<!DOCTYPE html>\
<html lang=\"en\">\
<head>\
    <meta charset=\"UTF-8\">\
    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\
    <title>Formulario WiFi</title>\
    <style>\
        body {\
            font-family: Arial, sans-serif;\
            background-color: #f4f4f4;\
            margin: 0;\
            padding: 0;\
            display: flex;\
            align-items: center;\
            justify-content: center;\
            height: 100vh;\
        }\
        form {\
            background-color: #fff;\
            padding: 20px;\
            border-radius: 8px;\
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);\
            width: 300px;\
        }\
        label {\
            display: block;\
            margin-bottom: 8px;\
            font-weight: bold;\
        }\
        input {\
            width: 100%;\
            padding: 8px;\
            margin-bottom: 16px;\
            box-sizing: border-box;\
            border: 1px solid #ccc;\
            border-radius: 4px;\
        }\
        button {\
            background-color: #4caf50;\
            color: white;\
            padding: 10px;\
            border: none;\
            border-radius: 4px;\
            cursor: pointer;\
        }\
        button:hover {\
            background-color: #45a049;\
        }\
    </style>\
</head>\
<body>\
    <h1> Config Wifi</h1>\
    <form action=\"/submit\" method=\"post\">\
        <label for=\"ssid\">SSID:</label>\
        <input type=\"text\" id=\"ssid\" name=\"ssid\" placeholder=\"Ingrese el SSID\" required maxlength=\"20\">\
        <label for=\"password\">Contraseña:</label>\
        <input type=\"password\" id=\"password\" name=\"password\" placeholder=\"Ingrese la contraseña\" required maxlength=\"20\">\
        <button type=\"submit\">Conectar</button>\
    </form>\
</body>\
</html>\
";
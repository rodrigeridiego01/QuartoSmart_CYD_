#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#define LGFX_USE_V1
#include <LovyanGFX.hpp>

class LGFX_CYD : public lgfx::LGFX_Device {
    lgfx::Panel_ST7789  _panel_instance;
    lgfx::Bus_SPI       _bus_instance;
public:
    LGFX_CYD() {
        auto bus_cfg = _bus_instance.config();
        bus_cfg.spi_host = VSPI_HOST;
        bus_cfg.spi_mode = 0;
        bus_cfg.freq_write = 20000000;
        bus_cfg.pin_sclk = 14;
        bus_cfg.pin_mosi = 13;
        bus_cfg.pin_miso = 12;
        bus_cfg.pin_dc   = 2;
        _bus_instance.config(bus_cfg);
        _panel_instance.setBus(&_bus_instance);

        auto panel_cfg = _panel_instance.config();
        panel_cfg.pin_cs           = 15;
        panel_cfg.pin_rst          = 4;
        panel_cfg.panel_width      = 240; 
        panel_cfg.panel_height     = 320; 
        panel_cfg.invert           = true; // Inverte as cores pro CYD
        
        _panel_instance.config(panel_cfg);
        setPanel(&_panel_instance);
    }
};

extern LGFX_CYD lcd;
#endif
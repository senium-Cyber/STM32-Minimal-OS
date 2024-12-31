#ifndef TFT_DISPLAY_H
#define TFT_DISPLAY_H

#include "sensor_data.h"

void tft_init(void);
void tft_clear(void);
void tft_display_sensor_data(SensorData data);
void tft_print(const char *msg);

#endif // TFT_DISPLAY_H

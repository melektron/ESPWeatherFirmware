/**
 * @file oled.hpp
 * @author Nilusink
 * @brief utility functions for the oled
 * @version 0.8
 * @date 2023-02-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once
#include <U8g2lib.h>
#include "sensor/sensor.hpp"


#define GRAPH_WIDTH 128
#define GRAPH_HEIGHT 34
#define GRAPH_X 0
#define GRAPH_Y 30


namespace OLED
{
    extern U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2;
    extern double last_data[GRAPH_WIDTH];
    extern uint8_t curr_pop;

    /**
     * @brief setup the display
     * 
     */
    void setup();

    /**
     * @brief update the display
     * 
     * @param d weather data
     */
    void update_display(Sensor::w_data_t d);

    void draw_graph(Sensor::w_data_t d);
}

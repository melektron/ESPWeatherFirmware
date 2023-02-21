#include "oled.hpp"
#include <cmath>


// utility functions
double d_map(double x, double in_min, double in_max, double out_min, double out_max)
{
    // magic
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


double d_max(double arr[], uint8_t length=GRAPH_WIDTH)
{
    double curr_max = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] > curr_max)
        {
            curr_max = arr[i];
        }
    }

    return curr_max;
}

double d_min(double arr[], uint8_t length=GRAPH_WIDTH)
{
    double curr_min = arr[0];
    for (int i = 1; i < length; i++)
    {
        if (arr[i] < curr_min)
        {
            curr_min = arr[i];
        }
    }

    return curr_min;
}


// display stuff
U8G2_SH1106_128X64_NONAME_F_HW_I2C OLED::u8g2(U8G2_R0);
double OLED::last_data[GRAPH_WIDTH];
uint8_t OLED::curr_pop = 0;


void OLED::setup()
{
    u8g2.begin();
}


void OLED::update_display(Sensor::w_data_t d)
{
    u8g2.firstPage();
    u8g2.setFont(u8g2_font_ncenB08_tr);

    // temperature
    char buff[64];

    sprintf(buff, "%.1f C", d.temperature);
    u8g2.drawStr(16, (uint8_t)(GRAPH_Y / 2), buff);

    sprintf(buff, "%.1f %s", d.humidity, "%");
    u8g2.drawStr(82, (uint8_t)(GRAPH_Y / 2), buff);

    u8g2.drawTriangle(52, 0, 76, 0, 64, 12);

    u8g2.nextPage();
}


void OLED::draw_graph(Sensor::w_data_t d)
{
    // move all items one up
    for (int i = curr_pop; i > -1; i--)
    {
        last_data[i+1] = last_data[i];
    }

    // insert new values
    last_data[0] = d.temperature;

    // draw graph
    double max_val = d_max(last_data, curr_pop) + .1;
    double min_val = d_min(last_data, curr_pop) - .1;

    uint8_t last = 0;
    for (int i = 0; i < curr_pop; i++)
    {
        uint8_t x = GRAPH_X + (GRAPH_WIDTH - i);
        uint8_t y = GRAPH_Y + (d_map(last_data[i], min_val, max_val, GRAPH_HEIGHT, 0));

        u8g2.drawPixel(x, y);

        if (i != 0)
        {
            for (int dy = y; dy < last; dy++)
            {
                u8g2.drawPixel(x, dy);
            }
            for (int dy = y; dy > last; dy--)
            {
                u8g2.drawPixel(x, dy);
            }
        }

        last = y;
    }

    if (curr_pop < GRAPH_WIDTH-1)
    {
        curr_pop++;
    }

    u8g2.nextPage();
}

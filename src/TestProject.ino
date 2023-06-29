SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#include "oled-wing-adafruit.h"
OledWingAdafruit display;

uint16_t value;
String stringOne = "Test";

void setup()
{
    pinMode(A5, INPUT);
    pinMode(D4, INPUT);
    pinMode(D5, INPUT);

    pinMode(D3, OUTPUT);

    display.setup();
}
void loop()
{
    display.loop();
    value = analogRead(A5);
    bool left = digitalRead(D4);
    bool right = digitalRead(D5);
    if (value <= 1024)
    {
        stringOne = "AND";
        if (left == true && right == true)
        {
            digitalWrite(D3, HIGH);
        }
        if (left == false && right == false)
        {

            digitalWrite(D3, LOW);
        }
        if (left != right)
        {

            digitalWrite(D3, LOW);
        }
    }
    if (value > 1024 && value <= 2048)
    {
        stringOne = "OR";
        if (left == true && right == true)
        {
            digitalWrite(D3, HIGH);
        }
        if (left == false && right == false)
        {
            digitalWrite(D3, LOW);
        }
        if (left != right)
        {

            digitalWrite(D3, HIGH);
        }
    }
    if (value > 2048 && value <= 3072)
    {
        stringOne = "XOR";
        if (left == right)
        {
            digitalWrite(D3, LOW);
        }
    }
    if (left != right)
    {
        digitalWrite(D3, HIGH);
    }
    if (value > 3072 && value <= 4096)
    {
        stringOne = "NAND";
        if (left == true && right == false)
        {
            digitalWrite(D3, LOW);
        }
        if (left == false && right == false)
        {
            digitalWrite(D3, HIGH);
        }
        if (left != right)
        {
            digitalWrite(D3, HIGH);
        }
    }
    display.clearDisplay();
    display.display();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println(stringOne);
    display.display();
}

#include <Arduino.h>
#include <FastLED.h>

namespace
{
constexpr fl::u8 kDataPin {16};
constexpr int kNumberOfLeds {1};
constexpr std::uint16_t kHalfSecondDelay {500U};
CRGB g_leds[kNumberOfLeds];
CRGB& g_led = g_leds[0];

constexpr int kRedLEDPin {0};
constexpr int kGreenLEDPin {1};
constexpr int kYellowLEDPin {2};
} // namespace

void setup()
{
    // put your setup code here, to run once:
    FastLED.addLeds<NEOPIXEL, kDataPin>(g_leds, kNumberOfLeds);
    g_led = CRGB::Blue;
    FastLED.show();
    // setup input pins
    pinMode(kRedLEDPin, PinMode::INPUT_PULLUP);
    pinMode(kGreenLEDPin, PinMode::INPUT_PULLUP);
    pinMode(kYellowLEDPin, PinMode::INPUT_PULLUP);
}

void CheckButtonsPressed()
{
    if (digitalRead(kRedLEDPin) == LOW)
    {
        g_led = CRGB::Red;
    }
    else if (digitalRead(kGreenLEDPin) == LOW)
    {
        g_led = CRGB::Green;
    }
    else if (digitalRead(kYellowLEDPin) == LOW)
    {
        g_led = CRGB::Yellow;
    }

    FastLED.show();
}

void loop()
{
    CheckButtonsPressed();
}

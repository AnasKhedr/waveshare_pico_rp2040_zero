#include <Arduino.h>
#include <FastLED.h>

namespace
{
constexpr fl::u8 kDataPin {16};
constexpr int kNumberOfLeds {1};
constexpr std::uint16_t kHalfSecondDelay {500U};
CRGB g_leds[kNumberOfLeds];
CRGB& g_led = g_leds[0];
} // namespace

void setup()
{
    // put your setup code here, to run once:
    FastLED.addLeds<NEOPIXEL, kDataPin>(g_leds, kNumberOfLeds);
}

void loop()
{
    // Set the LED to red, wait for half a second
    g_led = CRGB::Red;
    FastLED.show();
    delay(kHalfSecondDelay);

    // Turn the LED off, wait for half a second
    g_led = CRGB::Black;
    FastLED.show();
    delay(kHalfSecondDelay);

    // Set the LED to Cyan, wait for half a second
    g_led = CRGB::Cyan;
    FastLED.show();
    delay(kHalfSecondDelay);

    // Turn the LED off, wait for half a second
    g_led = CRGB::Black;
    FastLED.show();
    delay(kHalfSecondDelay);
}

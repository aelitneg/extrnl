#pragma once

#include <JuceHeader.h>

enum ThemeColours
{
    red,
    green,
    blue,
    lightGray,
    lightGrayWithOpacity,
    gray,
    darkGray,
    black,
    blackWithOpacity,
};

class Theme : public juce::LookAndFeel_V4
{
public:
    Theme()
    {
        // Set custom colors
        setColour(ThemeColours::red, red);
        setColour(ThemeColours::green, green);
        setColour(ThemeColours::blue, blue);
        setColour(ThemeColours::lightGray, lightGray);
        setColour(ThemeColours::lightGrayWithOpacity, lightGrayWithOpacity);
        setColour(ThemeColours::gray, gray);
        setColour(ThemeColours::darkGray, darkGray);
        setColour(ThemeColours::black, black);
        setColour(ThemeColours::blackWithOpacity, blackWithOpacity);

        setColour(juce::ResizableWindow::backgroundColourId, darkGray);
    }

private:
    juce::Colour red{255, 86, 63};
    juce::Colour green{23, 226, 125};
    juce::Colour blue{25, 125, 230};
    juce::Colour lightGray{207, 207, 207};
    juce::Colour lightGrayWithOpacity{(juce::uint8)207, (juce::uint8)207, (juce::uint8)207, 0.5f};
    juce::Colour gray{214, 214, 214};
    juce::Colour darkGray{143, 143, 143};
    juce::Colour black{0, 0, 0};
    juce::Colour blackWithOpacity{(juce::uint8)0, (juce::uint8)0, (juce::uint8)0, 0.5f};
};

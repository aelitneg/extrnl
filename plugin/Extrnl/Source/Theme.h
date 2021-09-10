#pragma once

#include <JuceHeader.h>

namespace Extrnl {
    enum ThemeColours
    {
        blue,
        green,
        orange,
        lightGray,
        gray,
        black,
    };

    class Theme : public juce::LookAndFeel_V4
    {
    public:
        Theme();
        
    private:
        juce::Colour blue{25, 125, 230};
        juce::Colour green{23, 226, 125};
        juce::Colour orange{255, 177, 0};
        juce::Colour lightGray{214, 214, 214};
        juce::Colour gray{196, 196, 196};
        juce::Colour black{0, 0, 0};
    };
}

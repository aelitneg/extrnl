#pragma once

#include <JuceHeader.h>

#include "../Theme.h"

class Container : public juce::Component
{
public:
    Container()
    {
    }

    ~Container() override
    {
    }

    void paint(juce::Graphics &g) override
    {
        g.fillAll(getLookAndFeel().findColour(ThemeColours::darkGray));
        
        g.setColour(juce::Colours::white);
        g.setFont(14.0f);
        g.drawText("Container", getLocalBounds(),
                   juce::Justification::centred, true); // draw some placeholder text
    }

    void resized() override
    {
    }

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Container)
};

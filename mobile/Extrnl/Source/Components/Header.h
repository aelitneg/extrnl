#pragma once

#include <JuceHeader.h>

#include "../Theme.h"

class Header : public juce::Component
{
public:
    Header()
    {
        // Configure font
        font.setHeight(20.0f);
        font.setBold(true);
    }

    ~Header() override
    {
    }

    void paint(juce::Graphics &g) override
    {
        // Fill background
        g.fillAll(getLookAndFeel().findColour(ThemeColours::darkGray));

        // Draw drop shadow
        shadowRect = getLocalBounds();
        shadowRect.setHeight(shadowRect.getHeight() - shadowRadius);
        shadow.drawForRectangle(g, shadowRect);

        // Draw header
        headerRect = getLocalBounds();
        headerRect.setHeight(getHeight() - shadowRadius);
        g.setColour(getLookAndFeel().findColour(ThemeColours::lightGray));
        g.fillRect(headerRect);

        // Draw title
        g.setFont(font);
        g.setColour(getLookAndFeel().findColour(ThemeColours::black));
        g.drawText("extrnl", headerRect, juce::Justification::centred, true);
    }

    void resized() override
    {
    }

private:
    juce::Font font;

    juce::Rectangle<int> shadowRect;
    juce::Rectangle<int> headerRect;

    juce::Colour shadowColour{0.0f, 0.0f, 0.0f, 0.4f};
    int shadowRadius{3};
    juce::Point<int> shadowOffset{0, 2};

    juce::DropShadow shadow{shadowColour, shadowRadius, shadowOffset};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Header)
};

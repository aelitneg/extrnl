#pragma once

#include <JuceHeader.h>

#include "../Theme.h"
#include "./TransportButton.h"

class Container : public juce::Component
{
public:
    Container(juce::ValueTree appState)
        : localState(appState),
          transportButton(localState.getChildWithName(State::transportStateNode))
    {
        addAndMakeVisible(transportButton);
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
        // Initialise flexBox
        juce::FlexBox flexBox;
        flexBox.flexDirection = juce::FlexBox::Direction::column;
        flexBox.alignContent = juce::FlexBox::AlignContent::center;
        flexBox.alignItems = juce::FlexBox::AlignItems::center;
        
        // Add TransportButton to flexBox
        juce::FlexItem flexTransportButton(transportButton);
        flexBox.items.add(flexTransportButton.withMinWidth(200).withMinHeight(200));
        
        // Draw flexbox layout
        int padding{20};
        int marginY{40};
        flexBox.performLayout(juce::Rectangle<int>(padding / 2,
                                                   marginY + padding / 2,
                                                   getWidth() - padding,
                                                   getHeight() - marginY - padding));
    }

private:
    juce::ValueTree localState;
    
    TransportButton transportButton;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Container)
};

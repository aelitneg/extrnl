#pragma once

#include <JuceHeader.h>

#include "../Theme.h"
#include "./SourceList.h"
#include "./TransportButton.h"

class Container : public juce::Component
{
public:
    Container(juce::ValueTree appState)
        : localState(appState),
          sourceList(localState.getChildWithName(State::selectedSourceStateNode),
                     localState.getChildWithName(State::sourceListStateNode)),
          transportButton(localState.getChildWithName(State::transportStateNode))
    {
        addAndMakeVisible(sourceList);
        addAndMakeVisible(transportButton);
    }

    ~Container() override
    {
    }

    void paint(juce::Graphics &g) override
    {
        g.fillAll(getLookAndFeel().findColour(ThemeColours::darkGray));
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
        flexBox.items.add(flexTransportButton.withWidth(200).withHeight(200).withAlignSelf(juce::FlexItem::AlignSelf::center));
        
        // Add SourceList to flexBox
        int sourceListMargin{40};
        juce::FlexItem flexSourceList(sourceList);
        flexBox.items.add(flexSourceList.withWidth(getWidth() - sourceListMargin).withMinHeight(50).withMargin(sourceListMargin));
        
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
    
    SourceList sourceList;
    TransportButton transportButton;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Container)
};

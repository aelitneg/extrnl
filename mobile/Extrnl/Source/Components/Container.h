#pragma once

#include <JuceHeader.h>

#include "../Theme.h"
#include "SourceList.h"
#include "SourceDetail.h"
#include "TransportButton.h"

class Container : public juce::Component
{
public:
    Container(juce::ValueTree appState)
        : localState(appState),
          sourceList(localState.getChildWithName(State::selectedSourceStateNode),
                     localState.getChildWithName(State::sourceListStateNode)),
          sourceDetail(localState.getChildWithName(State::selectedSourceStateNode)),
          transportButton(localState.getChildWithName(State::transportStateNode))
    {
        // Initialise flexbox
        flexBox.flexDirection = juce::FlexBox::Direction::column;
        flexBox.alignContent = juce::FlexBox::AlignContent::center;
        flexBox.alignItems = juce::FlexBox::AlignItems::center;

        // Initialise child components
        addAndMakeVisible(sourceList);
        addAndMakeVisible(sourceDetail);
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
        // Add TransportButton to flexBox
        juce::FlexItem flexTransportButton(transportButton);
        flexBox.items.add(flexTransportButton.withWidth(200).withHeight(200).withMargin(componentMargin).withAlignSelf(juce::FlexItem::AlignSelf::center));

        // Add SourceList to flexBox
        juce::FlexItem flexSourceList(sourceList);
        flexBox.items.add(flexSourceList.withWidth(getWidth() - (componentMargin.left + componentMargin.right)).withMinHeight(50).withMargin(componentMargin));

        // Add SourceDetail to flexBox
        juce::FlexItem flexSourceDetail(sourceDetail);
        flexBox.items.add(flexSourceDetail.withMargin(componentMargin).withFlex(1));

        // Draw flexbox layout
        flexBox.performLayout(juce::Rectangle<int>(margin.left,
                                                   margin.top,
                                                   getWidth() - (margin.left + margin.right),
                                                   getHeight() - (margin.top + margin.bottom)));
    }

private:
    juce::ValueTree localState;

    juce::FlexBox flexBox;
    juce::FlexItem::Margin margin{30, 10, 10, 10};
    juce::FlexItem::Margin componentMargin{20};

    SourceList sourceList;
    SourceDetail sourceDetail;
    TransportButton transportButton;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Container)
};

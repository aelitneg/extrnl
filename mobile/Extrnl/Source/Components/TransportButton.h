#pragma once

#include <JuceHeader.h>

#include "../FontAwesome.h"
#include "../State.h"
#include "../Theme.h"

class TransportButton : public juce::DrawableButton, juce::ValueTree::Listener, juce::Button::Listener
{
public:
    TransportButton(juce::ValueTree appTransportState)
        : juce::DrawableButton("transportButton", juce::DrawableButton::ButtonStyle::ImageOnButtonBackground),
          transportState(appTransportState)
    {
        // Setup state listener
        transportState.addListener(this);
        
        // Setup button listener
        addListener(this);
        
        // Apply theme
        setLookAndFeel(&theme);
        
        // Initialise play icon
        playIcon = FontAwesome::getDrawable("play");
        playIcon->replaceColour(juce::Colours::black, getLookAndFeel().findColour(ThemeColours::green));
        
        // Initialise stop icon
        stopIcon = FontAwesome::getDrawable("stop");
        stopIcon->replaceColour(juce::Colours::black, getLookAndFeel().findColour(ThemeColours::red));
    }

    ~TransportButton() override
    {
        // Cleanup listeners
        transportState.removeListener(this);
        removeListener(this);
        
        // Cleanup theme
        setLookAndFeel(nullptr);
    }
    
    void paintButton(juce::Graphics &g,
                     bool shouldDrawButtonAsHighlighted,
                     bool shouldDrawButtonAsDown) override
    {
        // Fill background
        g.fillAll(getLookAndFeel().findColour(shouldDrawButtonAsDown ? ThemeColours::lightGrayWithOpacity : ThemeColours::lightGray));
        
        // Draw border
        g.setColour(getLookAndFeel().findColour(shouldDrawButtonAsDown ? ThemeColours::blackWithOpacity : ThemeColours::black));
        g.drawRect(getLocalBounds(), 2);
        
        // Draw icon
        icon = getIcon();
        float padding {getWidth() / 2.0f};
        juce::Rectangle<float> iconBounds(0.0f + (padding / 2),
                                          0.0f + (padding / 2),
                                          getWidth() - padding,
                                          getHeight() - padding);
        icon->drawWithin(g, iconBounds, juce::RectanglePlacement(), shouldDrawButtonAsDown ? 0.5f : 1.0f);
    }
    
    juce::Drawable* getIcon()
    {
        switch((State::TransportState)(int)transportState.getProperty(State::transportState)) {
            case State::TransportState::Stopped:
                return playIcon;
            case State::TransportState::Playing:
                return stopIcon;
        }
    }
    
    void valueTreePropertyChanged(juce::ValueTree &transportStateNode, const juce::Identifier &property) override
    {
        if (property == State::transportState) {
            repaint();
        }
    }
    
    void buttonClicked(juce::Button *button) override
    {
        switch((State::TransportState)(int)transportState.getProperty(State::transportState)) {
            case State::TransportState::Stopped:
                transportState.setProperty(State::transportState, State::TransportState::Playing, nullptr);
                break;
            case State::TransportState::Playing:
                transportState.setProperty(State::transportState, State::TransportState::Stopped, nullptr);
                break;
        }
    }

private:
    juce::ValueTree transportState;
    
    Theme theme;
    juce::Drawable *icon;
    juce::Drawable *playIcon;
    juce::Drawable *stopIcon;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TransportButton)
};

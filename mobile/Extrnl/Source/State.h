#pragma once

#include <JuceHeader.h>

class State
{
public:
    // Enums
    enum TransportState {
        Stopped,
        Playing,
    };
    
    // State Identifiers
    static juce::Identifier appStateNode;
    static juce::Identifier transportStateNode;
    static juce::Identifier transportState;
};

#pragma once

#include <JuceHeader.h>

class State
{
public:
    // Enums
    enum TransportState
    {
        Stopped,
        Starting,
        Playing,
        Stopping
    };

    // State Identifiers
    static juce::Identifier appStateNode;
    static juce::Identifier transportStateNode;
    static juce::Identifier transportState;
    static juce::Identifier selectedSourceStateNode;
    static juce::Identifier sourceListStateNode;
    static juce::Identifier sourceNode;
    static juce::Identifier sourceId;
    static juce::Identifier sourceName;
    static juce::Identifier sourceSampleRate;
    static juce::Identifier sourceSampleRateConversion;
    static juce::Identifier sourceBitDepth;
    static juce::Identifier sourceBufferLength;
};

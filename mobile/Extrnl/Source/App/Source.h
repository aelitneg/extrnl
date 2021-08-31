#pragma once

#include <JuceHeader.h>

class Source
{
public:
    Source(int id, juce::String name);
    Source(int id, juce::String name, int sampleRate, bool sampleRateConversion, int bitDepth, int bufferLength);

    Source(Source &other);
    ~Source();

    int getId();
    void setId(int newId);

    juce::String getName();
    void setName(juce::String newName);

    int getSampleRate();
    void setSampleRate(int newSampleRate);

    bool getSampleRateConversion();
    void setSampleRateConversion(bool newSampleRateConversion);

    int getBitDepth();
    void setBitDepth(int newBitDepth);

    int getBufferLength();
    void setBufferLength(int newBufferLength);

private:
    int id;
    juce::String name;
    int sampleRate{0};
    bool sampleRateConversion{false};
    int bitDepth{0};
    int bufferLength{0};
};

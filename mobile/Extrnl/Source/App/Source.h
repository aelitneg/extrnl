#pragma once

#include <JuceHeader.h>

class Source
{
public:
    Source(int id, juce::String name);
    Source(Source &other);
    ~Source();
    
    int id;

private:
    juce::String name;
};

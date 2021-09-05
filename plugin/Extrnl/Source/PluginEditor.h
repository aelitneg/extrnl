#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class ExtrnlAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    ExtrnlAudioProcessorEditor(ExtrnlAudioProcessor &);
    ~ExtrnlAudioProcessorEditor() override;

    void paint(juce::Graphics &) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    ExtrnlAudioProcessor &audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExtrnlAudioProcessorEditor)
};

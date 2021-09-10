#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "Theme.h"
#include "Components/Container.h"

class ExtrnlAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    ExtrnlAudioProcessorEditor(ExtrnlAudioProcessor &);
    ~ExtrnlAudioProcessorEditor() override;

    void paint(juce::Graphics &) override;
    void resized() override;

private:
    ExtrnlAudioProcessor &audioProcessor;
    
    Extrnl::Theme theme;
    juce::BorderSize<int> margin{25};
    
    Extrnl::Container container;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExtrnlAudioProcessorEditor)
};

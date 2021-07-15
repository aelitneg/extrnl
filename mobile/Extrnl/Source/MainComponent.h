#pragma once

#include <JuceHeader.h>

#include "State.h"
#include "Theme.h"
#include "Components/Container.h"
#include "Components/Header.h"

class MainComponent : public juce::AudioAppComponent, juce::ValueTree::Listener, State
{
public:
    MainComponent(juce::ValueTree &appState);
    ~MainComponent() override;

    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override;
    void getNextAudioBlock(const juce::AudioSourceChannelInfo &bufferToFill) override;
    void releaseResources() override;

    void paint(juce::Graphics &g) override;
    void resized() override;

    void valueTreeChildAdded(juce::ValueTree &parent, juce::ValueTree &child) override;
    void valueTreeChildRemoved(juce::ValueTree &parent, juce::ValueTree &child, int index) override;

private:
    juce::ValueTree localState;

    Theme theme;
    Container container;
    Header header;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};

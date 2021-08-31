#pragma once

#include <memory>
#include <vector>
#include <JuceHeader.h>

#include "../State.h"
#include "./Source.h"

class Extrnl : public juce::ValueTree::Listener
{
public:
    Extrnl();
    ~Extrnl();

    void initialiseState(juce::ValueTree appState);

    // State listener callbacks
    void valueTreeChildAdded(juce::ValueTree &parent, juce::ValueTree &child) override;
    void valueTreeChildRemoved(juce::ValueTree &parent, juce::ValueTree &child, int index) override;
    void valueTreePropertyChanged(juce::ValueTree &node, const juce::Identifier &property) override;

    // TODO: Remove mock data
    void mockData();

private:
    juce::ValueTree localState;

    std::vector<std::unique_ptr<Source>> sources;
    std::unique_ptr<Source> selectedSource;
    State::TransportState transportState;

    void selectedSourceChanged();
    void transportStateChanged(juce::ValueTree &node, const juce::Identifier &property);

    void play();
    void stop();
};

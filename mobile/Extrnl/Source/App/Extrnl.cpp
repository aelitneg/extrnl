#include "Extrnl.h"

Extrnl::Extrnl()
{
}

Extrnl::~Extrnl()
{
}

void Extrnl::initialiseState(juce::ValueTree appState)
{
    localState = juce::ValueTree(appState);
    localState.addListener(this);
    
    // TODO: Remove mockData
    mockData();
}

void Extrnl::valueTreeChildAdded(juce::ValueTree &parent, juce::ValueTree &child)
{
    juce::Logger::getCurrentLogger()->writeToLog("Extrnl::valueTreeChildAdded");
    
    juce::Identifier type(parent.getType());
    
    if (type == State::selectedSourceStateNode)
    {
        return selectedSourceChanged();
    }
}

void Extrnl::valueTreeChildRemoved(juce::ValueTree &parent, juce::ValueTree &child, int index)
{
    juce::Logger::getCurrentLogger()->writeToLog("Extrnl::valueTreeChildRemoved");
}

void Extrnl::selectedSourceChanged()
{
    // Get current source ID
    int sourceId = localState.getChildWithName(State::selectedSourceStateNode)
        .getChild(0)
        .getProperty(State::sourceId);
    
    // Iterate through sources to find ID and set selected source
    for (auto it = sources.begin(); it != sources.end(); it++)
    {
        if (it->get()->getId() == sourceId)
        {
            selectedSource.reset(it->get());
            return;
        }
    }
}

// TODO: Remove mockData
void Extrnl::mockData()
{
    juce::ValueTree sourceListState = localState.getChildWithName(State::sourceListStateNode);
    
    std::vector<std::unique_ptr<Source>> mockSources;
    
    mockSources.push_back(std::unique_ptr<Source>(new Source(0, "2TRK", 48000, false, 24, 512)));
    mockSources.push_back(std::unique_ptr<Source>(new Source(1, "Kick", 44100, true, 16, 512)));
    mockSources.push_back(std::unique_ptr<Source>(new Source(2, "Bass", 44100, true, 16, 512)));
    
    for (auto it = mockSources.begin(); it != mockSources.end(); it++)
    {
        juce::ValueTree mockNode(State::sourceNode);
        
        mockNode.setProperty(State::sourceId, it->get()->getId() + 1, nullptr);
        mockNode.setProperty(State::sourceName, it->get()->getName(), nullptr);
        mockNode.setProperty(State::sourceSampleRate, it->get()->getSampleRate(), nullptr);
        mockNode.setProperty(State::sourceSampleRateConversion, it->get()->getSampleRateConversion(), nullptr);
        mockNode.setProperty(State::sourceBitDepth, it->get()->getBitDepth(), nullptr);
        mockNode.setProperty(State::sourceBufferLength, it->get()->getBufferLength(), nullptr);
        
        sourceListState.addChild(mockNode, -1, nullptr);
        
        sources.push_back(std::unique_ptr<Source>(it->release()));
    }
}

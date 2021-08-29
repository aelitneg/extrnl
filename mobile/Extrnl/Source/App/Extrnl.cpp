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
        if (it->get()->id == sourceId)
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
    
    juce::String mocks[3]{"2TRK", "Kick", "Bass"};
    for (int i = 0; i < sizeof(mocks) / sizeof(juce::String); i++)
    {
        std::unique_ptr<Source> mock(new Source((i + 1),mocks[i]));
        
        juce::ValueTree mockNode(State::sourceNode);
        mockNode.setProperty(State::sourceId, i + 1, nullptr);
        mockNode.setProperty(State::sourceName, mocks[i], nullptr);
        sourceListState.addChild(mockNode, -1, nullptr);
        
        sources.push_back(std::unique_ptr<Source>(mock.release()));
    }
}

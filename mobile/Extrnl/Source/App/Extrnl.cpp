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
    juce::Identifier type(parent.getType());

    if (type == State::selectedSourceStateNode)
    {
        return selectedSourceChanged(child);
    }
}

void Extrnl::valueTreeChildRemoved(juce::ValueTree &parent, juce::ValueTree &child, int index)
{
}

void Extrnl::valueTreePropertyChanged(juce::ValueTree &node, const juce::Identifier &property)
{
    if (node.getType() == State::transportStateNode)
    {
        transportStateChanged(node, property);
    }
}

void Extrnl::selectedSourceChanged(juce::ValueTree &sourceNode)
{
    // Get current source ID
    int sourceId = sourceNode.getProperty(State::sourceId);

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

void Extrnl::transportStateChanged(juce::ValueTree &node, const juce::Identifier &property)
{
    switch ((State::TransportState)(int)node.getProperty(property))
    {
    case State::TransportState::Stopped:
        break;
    case State::TransportState::Starting:
        play();
        break;
    case State::TransportState::Playing:
        break;
    case State::TransportState::Stopping:
        stop();
        break;
    }
}

void Extrnl::play()
{
    transportState = State::TransportState::Playing;
    localState.getChildWithName(State::transportStateNode).setProperty(State::transportState, transportState, nullptr);
}

void Extrnl::stop()
{
    transportState = State::TransportState::Stopped;
    localState.getChildWithName(State::transportStateNode).setProperty(State::transportState, transportState, nullptr);
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

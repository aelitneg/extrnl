#include "MainComponent.h"

MainComponent::MainComponent(juce::ValueTree &appState) : localState(appState), container(localState)
{
    // Setup state listener
    localState.addListener(this);

    // Apply theme
    setLookAndFeel(&theme);

    // Add child components
    addAndMakeVisible(header);
    addAndMakeVisible(container);

    // Set size of component after adding child components
    setSize(getParentWidth(), getParentHeight());

    // Setup audio (no inputs)
    setAudioChannels(0, 2);
}

MainComponent::~MainComponent()
{
    shutdownAudio();

    // Cleanup theme
    setLookAndFeel(nullptr);
}

void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
    // Called when audio is started or settings change (sample rate, block size, etc)
    // Called on the audio thread, not GUI thread
    // More info: see help for AudioProcessor::prepareToPlay()
}

void MainComponent::getNextAudioBlock(const juce::AudioSourceChannelInfo &bufferToFill)
{
    bufferToFill.clearActiveBufferRegion();
}

void MainComponent::releaseResources()
{
    // Called when audio device stops or prior to changing settings
}

void MainComponent::paint(juce::Graphics &g)
{
    // Fill background
    g.fillAll(getLookAndFeel().findColour(ThemeColours::lightGray));
}

void MainComponent::resized()
{
    // Called when mainContentComponent is resized
    // Update positions of child components here

    // Get SafeArea Insets for main display
    juce::BorderSize<int> safeAreaInsets;
    juce::Array<juce::Displays::Display> displays = juce::Desktop::getInstance().getDisplays().displays;
    for (auto it = std::begin(displays); it < std::end(displays); it++)
    {
        if (it->isMain)
        {
            safeAreaInsets = it->safeAreaInsets;
        }
    }

    // Draw header
    header.setBounds(getX() + safeAreaInsets.getLeft(),
                     getY() + safeAreaInsets.getTop(),
                     getWidth() - safeAreaInsets.getLeftAndRight(),
                     60);

    // Draw container
    container.setBounds(getX(),
                        header.getBottom(),
                        getWidth() - safeAreaInsets.getLeftAndRight(),
                        getHeight() - header.getHeight() - safeAreaInsets.getTopAndBottom());
}

void MainComponent::valueTreeChildAdded(juce::ValueTree &parent, juce::ValueTree &child)
{
}

void MainComponent::valueTreeChildRemoved(juce::ValueTree &parent, juce::ValueTree &child, int index)
{
}

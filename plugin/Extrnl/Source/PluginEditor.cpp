#include "PluginProcessor.h"
#include "PluginEditor.h"

ExtrnlAudioProcessorEditor::ExtrnlAudioProcessorEditor(ExtrnlAudioProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p)
{
    // Set size and apply theme
    setSize(475, 250);
    setLookAndFeel(&theme);
    
    // Add child components
    addAndMakeVisible(container);
}

ExtrnlAudioProcessorEditor::~ExtrnlAudioProcessorEditor()
{
    // Cleanup theme
    setLookAndFeel(nullptr);
}

void ExtrnlAudioProcessorEditor::paint(juce::Graphics &g)
{
    // Fill background
    g.fillAll(getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
}

void ExtrnlAudioProcessorEditor::resized()
{
    // Position main container with margins
    container.setBounds(margin.subtractedFrom(getLocalBounds()));
}

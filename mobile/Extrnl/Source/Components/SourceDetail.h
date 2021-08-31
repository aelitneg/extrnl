#pragma once

#include <JuceHeader.h>

#include "../State.h"
#include "../Theme.h"

class SourceDetail  : public juce::Component, juce::ValueTree::Listener
{
public:
    SourceDetail(juce::ValueTree appSelectedSource) : selectedSource(appSelectedSource)
    {
        // Initialise labels
        values[0].reset(new juce::Label("sampleRate", ""));
        values[1].reset(new juce::Label("sampleRateConversion", ""));
        values[2].reset(new juce::Label("bitDepth",""));
        values[3].reset(new juce::Label("bufferLength", ""));
        
        for (int i = 0; i < sizeof(values) / sizeof(std::unique_ptr<juce::Label>); i++)
        {
            addAndMakeVisible(values[i].get());
        }
        
        // Initialise font
        headerFont = Theme::getBaseFont();
        headerFont.setBold(true);
        headerFont.setHeight(20.0f);
        
        // Setup state listener
        selectedSource.addListener(this);
    }

    ~SourceDetail() override
    {
    }

    void paint (juce::Graphics& g) override
    {
        // Fill Background
        g.fillAll (getLookAndFeel().findColour(ThemeColours::lightGray));

        // Draw border
        g.setColour (getLookAndFeel().findColour(ThemeColours::black));
        g.drawRect (getLocalBounds(), 1);
        
        // Draw header
        juce::Rectangle<int> headerRect(0, 0, getWidth(), 32);
        g.setColour (getLookAndFeel().findColour(ThemeColours::blue));
        g.fillRect(headerRect);
        
        // Draw header border
        g.setColour(getLookAndFeel().findColour(ThemeColours::black));
        g.drawRect(headerRect, 1);
        
        // Draw header text
        g.setFont(headerFont);
        g.setColour(getLookAndFeel().findColour(ThemeColours::black));
        g.drawText ("Source Info",
                    juce::Rectangle<int>(padding,
                                         padding,
                                         headerRect.getWidth() - (padding * 2),
                                         headerRect.getHeight() - (padding * 2)),
                    juce::Justification::left, true);
        
        // Create container for details
        juce::FlexBox detailsContainer;
        detailsContainer.flexDirection = juce::FlexBox::Direction::column;
        
        // Add padding to container
        juce::Rectangle<int> detailsContainerRect(padding,
                                                  headerRect.getBottom() + padding,
                                                  getWidth() - (padding * 2),
                                                  getHeight() - headerRect.getHeight() - (padding * 2));
        
        // Create row for each detail
        for (int i = 0; i < sizeof(labels) / sizeof(juce::String); i++)
        {
            detailsContainer.items.add(juce::FlexItem().withFlex(1));
        }
        
        // Calculate layout for rows
        detailsContainer.performLayout(detailsContainerRect);
        
        // Add details to each row
        g.setFont(Theme::getBaseFont());
        for (int i = 0; i < sizeof(labels) / sizeof(juce::String); i++)
        {
            // Create container for row
            juce::FlexBox detailContainer;
            
            // Add details
            detailContainer.items.add(juce::FlexItem().withFlex(1).withHeight(detailsContainer.items[0].currentBounds.getHeight()));
            detailContainer.items.add(juce::FlexItem().withFlex(1).withHeight(detailsContainer.items[0].currentBounds.getHeight()));
            
            // Calculate layout for row
            detailContainer.performLayout(detailsContainer.items[i].currentBounds);
            
            // Draw details
            g.drawText(labels[i], detailContainer.items[0].currentBounds, juce::Justification::left, true);
            
            juce::Rectangle<float> valueBounds(detailContainer.items[1].currentBounds);
            values[i].get()->setBounds(juce::Rectangle<int>((int)valueBounds.getX(),
                                                            (int)valueBounds.getY(),
                                                            (int)valueBounds.getWidth(),
                                                            (int)valueBounds.getHeight()));
        }
    }
    
    void resized() override
    {
    }
    
    void valueTreeChildAdded(juce::ValueTree &parent, juce::ValueTree &child) override
    {
        // Update sample rate value
        values[0].get()->setText(parseSampleRate(child.getProperty(State::sourceSampleRate)),
                                 juce::NotificationType::dontSendNotification);
        
        // Update sample rate conversion value
        values[1].get()->setText(child.getProperty(State::sourceSampleRateConversion) ? "Active" : "Inactive",
                                 juce::NotificationType::dontSendNotification);
        
        // Update bit depth value
        values[2].get()->setText(child.getProperty(State::sourceBitDepth),
                                 juce::NotificationType::dontSendNotification);
        
        // Update buffer length value
        values[3].get()->setText(child.getProperty(State::sourceBufferLength),
                                 juce::NotificationType::dontSendNotification);
    }
    
    void valueTreeChildRemoved(juce::ValueTree &parent, juce::ValueTree &child, int index) override
    {
        // Clear sample rate value
        values[0].get()->setText("", juce::NotificationType::dontSendNotification);
        
        // Clear sample rate conversion value
        values[1].get()->setText("", juce::NotificationType::dontSendNotification);
        
        // Clear bit depth value
        values[2].get()->setText("", juce::NotificationType::dontSendNotification);
        
        // Clear buffer length value
        values[3].get()->setText("", juce::NotificationType::dontSendNotification);
    }

private:
    juce::ValueTree selectedSource;
    
    juce::String labels[4]{"Sample Rate", "SRC", "Bit Depth", "Buffer Length"};
    std::unique_ptr<juce::Label> values[4];
    
    juce::Font headerFont;
    int padding{10};
    
    juce::String parseSampleRate(juce::var var)
    {
        int sampleRate = (int)var;
        
        int sigFigs{1};
        if (sampleRate > 10000) { sigFigs++; }
        if (sampleRate % 1000) { sigFigs++; }
        
        juce::String sSampleRate = juce::String::toDecimalStringWithSignificantFigures((float)sampleRate / 1000,
                                                                                       sigFigs);
        return sSampleRate + juce::String(" kHz");
    }
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SourceDetail)
};

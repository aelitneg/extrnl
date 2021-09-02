#pragma once

#include <JuceHeader.h>

#include "../State.h"

class SourceList : public juce::ComboBox, juce::ComboBox::Listener, juce::ValueTree::Listener
{
public:
    SourceList(juce::ValueTree appSelectedSource, juce::ValueTree appSourceList)
        : selectedSource(appSelectedSource),
          sourceList(appSourceList)

    {
        // Configure ComboBox options
        setTextWhenNothingSelected("No Source Selected");
        setTextWhenNoChoicesAvailable("No Source Available");

        // Update options
        refreshSourceListItems();

        // Setup Listeners
        sourceList.addListener(this); // ValueTree listener
        addListener(this);            // ComboBox listener
    }

    ~SourceList() override
    {
        // Cleanup listeners
        sourceList.removeListener(this);
        removeListener(this);
    }

    void comboBoxChanged(juce::ComboBox *comboBox) override
    {
        // Update selected source state
        selectedSource.addChild(sourceList.getChild(comboBox->getSelectedItemIndex()).createCopy(),
                                0,
                                nullptr);
    }

    void valueTreeChildAdded(juce::ValueTree &parent, juce::ValueTree &child) override
    {
        // Update options when state is updated
        refreshSourceListItems();
    }

    void valueTreeChildRemoved(juce::ValueTree &parent, juce::ValueTree &child, int index) override
    {
        // Update options when state is updated
        refreshSourceListItems();
    }

    void refreshSourceListItems()
    {
        // Remove existing options
        clear();

        // Add option for each item in source list state
        for (int i = 0; i < sourceList.getNumChildren(); i++)
        {
            juce::ValueTree source(sourceList.getChild(i));
            addItem(sourceList.getChild(i).getProperty(State::sourceName),
                    sourceList.getChild(i).getProperty(State::sourceId));
        }
    }

private:
    juce::ValueTree selectedSource;
    juce::ValueTree sourceList;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SourceList)
};

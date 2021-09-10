
#include <JuceHeader.h>
#include "Container.h"

using namespace Extrnl;

Extrnl::Container::Container()
{
    titleFont.setHeight(28.f);
    titleFont.setBold(true);
}

Extrnl::Container::~Container()
{
}

void Extrnl::Container::paint (juce::Graphics& g)
{
    // Draw title
    g.setColour (getLookAndFeel().findColour(Extrnl::ThemeColours::black));
    g.setFont(titleFont);
    g.drawText ("extrnl", getLocalBounds(),
                juce::Justification::topLeft, true);
}

void Extrnl::Container::resized()
{
}

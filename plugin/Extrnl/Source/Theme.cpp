#include "Theme.h"

using namespace Extrnl;

Extrnl::Theme::Theme()
{
    // Set custom colours
    setColour(ThemeColours::blue, blue);
    setColour(ThemeColours::green, green);
    setColour(ThemeColours::orange, orange);
    setColour(ThemeColours::lightGray, lightGray);
    setColour(ThemeColours::black, black);
    
    // Override JUCE colours
    setColour(juce::ResizableWindow::backgroundColourId, lightGray);
    
    // Set default font
    setDefaultSansSerifTypefaceName("Helvetica Neue");
}

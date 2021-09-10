#pragma once

#include <JuceHeader.h>
#include "../Theme.h"

namespace Extrnl {
    class Container  : public juce::Component
    {
    public:
        Container();
        ~Container() override;

        void paint (juce::Graphics&) override;
        void resized() override;

    private:
        juce::Font titleFont;
        
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Container)
    };
}

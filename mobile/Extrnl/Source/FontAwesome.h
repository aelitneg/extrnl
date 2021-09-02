#pragma once

#include <JuceHeader.h>

class FontAwesome
{
public:
    static juce::Drawable *getDrawable(std::string icon)
    {
        auto assetsDir = juce::File::getSpecialLocation(juce::File::currentExecutableFile)
                             .getParentDirectory()
                             .getChildFile("Assets")
                             .getChildFile("Icons");

        if (!assetsDir.exists())
        {
            return nullptr;
        }

        auto resourceFile = assetsDir.getChildFile(juce::String(icon) + ".svg");
        if (!resourceFile.exists())
        {
            return nullptr;
        }

        return juce::Drawable::createFromSVGFile(resourceFile).release();
    }
};

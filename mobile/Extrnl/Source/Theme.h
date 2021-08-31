#pragma once

#include <JuceHeader.h>

#include "FontAwesome.h"

enum ThemeColours
{
    red,
    green,
    blue,
    lightGray,
    lightGrayWithOpacity,
    gray,
    darkGray,
    black,
    blackWithOpacity,
};

class Theme : public juce::LookAndFeel_V4
{
public:
    Theme()
    {
        // Set custom colours
        setColour(ThemeColours::red, red);
        setColour(ThemeColours::green, green);
        setColour(ThemeColours::blue, blue);
        setColour(ThemeColours::lightGray, lightGray);
        setColour(ThemeColours::lightGrayWithOpacity, lightGrayWithOpacity);
        setColour(ThemeColours::gray, gray);
        setColour(ThemeColours::darkGray, darkGray);
        setColour(ThemeColours::black, black);
        setColour(ThemeColours::blackWithOpacity, blackWithOpacity);
        
        // Override JUCE colours
        // Background
        setColour(juce::ResizableWindow::backgroundColourId, darkGray);
        
        // ComboBox
        setColour(juce::ComboBox::ColourIds::backgroundColourId, lightGray);
        setColour(juce::ComboBox::ColourIds::textColourId, black);
        setColour(juce::ComboBox::ColourIds::outlineColourId, black);
        setColour(juce::ComboBox::ColourIds::arrowColourId, black);
        
        // Label
        setColour(juce::Label::ColourIds::textColourId, black);
        
        // PopupMenu
        setColour(juce::PopupMenu::ColourIds::backgroundColourId, lightGray);
        setColour(juce::PopupMenu::ColourIds::textColourId, black);
    }
    
    juce::Font getComboBoxFont(juce::ComboBox& comboBox) override
    {
        return getFont();
    }
    
    juce::Font getPopupMenuFont() override
    {
        return getFont();
    }
    
    juce::Font getLabelFont(juce::Label &label) override
    {
        juce::Font labelFont = getFont();
        labelFont.setBold(true);
        return labelFont;
    }
    
    void drawPopupMenuItemWithOptions(juce::Graphics &g,
                                      const juce::Rectangle<int> &area,
                                      bool isHighlighted,
                                      const juce::PopupMenu::Item &item,
                                      const juce::PopupMenu::Options &options) override
    {
        // Use Flexbox layout
        juce::FlexBox flexBox;
        int padding{10};
        
        if (isHighlighted)
        {
            // Add container for icon
            juce::FlexItem icon;
            flexBox.items.add(icon.withWidth(30));
        }
        
        // Add container for label
        juce::FlexItem label;
        flexBox.items.add(label.withFlex(1).withMargin(padding));
        
        // Calculate container sizes
        flexBox.performLayout(juce::Rectangle<float>(padding,
                                                     padding,
                                                     area.getWidth() - padding * 2,
                                                     area.getHeight() - padding * 2));
        
        if (isHighlighted)
        {
            // Draw icon
            FontAwesome::getDrawable("volume-up")->drawWithin(g,
                                                              flexBox.items[0].currentBounds,
                                                              juce::RectanglePlacement(),
                                                              1.0f);
        }
        
        // Draw label
        g.setColour(black);
        g.setFont(getPopupMenuFont());
        g.drawText(item.text, flexBox.items[isHighlighted ? 1 : 0].currentBounds, juce::Justification::left);
        
        // Draw separator
        g.setColour(darkGray);
        g.drawLine(area.getX(),
                   area.getY() + area.getHeight(),
                   area.getWidth(),
                   area.getY() + area.getHeight(),
                   1.0f);
    }
    
    static juce::Font getBaseFont()
    {
        return juce::Font("Helvetica Neue", "Regular", 17.f);
    }

private:
    juce::Colour red{255, 86, 63};
    juce::Colour green{23, 226, 125};
    juce::Colour blue{25, 125, 230};
    juce::Colour lightGray{207, 207, 207};
    juce::Colour lightGrayWithOpacity{(juce::uint8)207, (juce::uint8)207, (juce::uint8)207, 0.5f};
    juce::Colour gray{214, 214, 214};
    juce::Colour darkGray{143, 143, 143};
    juce::Colour black{0, 0, 0};
    juce::Colour blackWithOpacity{(juce::uint8)0, (juce::uint8)0, (juce::uint8)0, 0.5f};
    
    juce::Font getFont()
    {
        return juce::Font ("Helvetica Neue", "Regular", 17.f);
    }
};

#include <JuceHeader.h>

#include "State.h"
#include "MainComponent.h"
#include "./App/Extrnl.h"

class ExtrnlApplication : public juce::JUCEApplication
{
public:
    ExtrnlApplication() {}

    const juce::String getApplicationName() override { return ProjectInfo::projectName; }
    const juce::String getApplicationVersion() override { return ProjectInfo::versionString; }
    bool moreThanOneInstanceAllowed() override { return true; }

    void initialise(const juce::String &commandLine) override
    {
        // Initialise app state
        appState = juce::ValueTree(State::appStateNode);
        
        // Initialise transport state
        appState.addChild(juce::ValueTree(State::transportStateNode), -1, nullptr);
        appState.getChildWithName(State::transportStateNode).setProperty(State::transportState,
                                                                         State::TransportState::Stopped,
                                                                         nullptr);
        // Initialise selected source state
        appState.addChild(juce::ValueTree(State::selectedSourceStateNode), -1, nullptr);
        
        // Initialise source list state
        appState.addChild(juce::ValueTree(State::sourceListStateNode), -1, nullptr);
        
        // Initialise app
        extrnl.reset(new Extrnl());
        extrnl.get()->initialiseState(appState);
        
        // Initialise UI
        mainWindow.reset(new MainWindow(getApplicationName(), appState));
    }

    void shutdown() override
    {
        mainWindow = nullptr; // (deletes our window)
    }

    void systemRequestedQuit() override
    {
        quit();
    }

    void anotherInstanceStarted(const juce::String &commandLine) override
    {
    }

    class MainWindow : public juce::DocumentWindow
    {
    public:
        MainWindow(juce::String name, juce::ValueTree &appState)
            : DocumentWindow(name,
                             juce::Desktop::getInstance().getDefaultLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId),
                             DocumentWindow::allButtons)
        {
            setUsingNativeTitleBar(true);
            setContentOwned(new MainComponent(appState), true);

#if JUCE_IOS || JUCE_ANDROID
            setFullScreen(true);
#else
            setResizable(true, true);
            centreWithSize(getWidth(), getHeight());
#endif

            setVisible(true);
        }

        void closeButtonPressed() override
        {
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainWindow)
    };

private:
    juce::ValueTree appState;
    std::unique_ptr<MainWindow> mainWindow;
    std::unique_ptr<Extrnl> extrnl;
};

// This macro generates the main() routine that launches the app.
START_JUCE_APPLICATION(ExtrnlApplication)

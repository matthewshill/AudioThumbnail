/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 4.2.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GainPluginAudioProcessorEditor::GainPluginAudioProcessorEditor (GainPluginAudioProcessor* ownerFilter)
    : AudioProcessorEditor(ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 1, 0.1);
    slider->setSliderStyle (Slider::Rotary);
    slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

GainPluginAudioProcessorEditor::~GainPluginAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    slider = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GainPluginAudioProcessorEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff27023b));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GainPluginAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    slider->setBounds (40, 176, 270, 160);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GainPluginAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]
    GainPluginAudioProcessor* processor = getProcessor();

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        //[/UserSliderCode_slider]
        
        processor->setParameterNotifyingHost(GainPluginAudioProcessor::Gain, (float)slider->getValue());
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...

void GainPluginAudioProcessorEditor::timerCallback()
{
    GainPluginAudioProcessor* processor = getProcessor();
    slider->setValue(processor->getParameter(GainPluginAudioProcessor::Gain), dontSendNotification);
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GainPluginAudioProcessorEditor"
                 componentName="" parentClasses="public AudioProcessorEditor_publicTimer"
                 constructorParams="GainPluginAudioProcessor* ownerFilter" variableInitialisers="AudioProcesssorEditor(ownedFilter)&#10;"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff27023b"/>
  <SLIDER name="new slider" id="c33e14073bee8387" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="40 176 270 160" min="0" max="1" int="0.10000000000000000555"
          style="Rotary" textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

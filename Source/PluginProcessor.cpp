/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
GainPluginAudioProcessor::GainPluginAudioProcessor()
{
    UserParams[Gain] = 0.0;
}

GainPluginAudioProcessor::~GainPluginAudioProcessor()
{
}

//==============================================================================
const String GainPluginAudioProcessor::getName() const
{
    return "GainPlugin";
}

int GainPluginAudioProcessor::getNumParameters()
{
    return totalNumParam;
}

float GainPluginAudioProcessor::getParameter(int index)
{
    switch (index) {
        case Gain:
            return UserParams[Gain];
        default:
            return 0.0f;
    }
}

void GainPluginAudioProcessor::setParamter(int index, float newValue)
{
    switch (index) {
        case Gain:
            UserParams[Gain] = newValue;
        default:
            return;
    }
}

const String GainPluginAudioProcessor::getParameterName(int index)
{
    switch (index) {
        case Gain:
            return "Gain";
            
        default:
            return String::empty;
    }
}

const String GainPluginAudioProcessor::getParameterText(int index)
{
    switch (index) {
        case Gain:
            return String(UserParams[Gain], 3);
            
        default:
            break;
    }
    return String::empty;
}

const String GainPluginAudioProcessor::getInputChannelName(int channelIndex) const
{
    return String (channelIndex + 1);
}

const String GainPluginAudioProcessor::getOutputChannelName(int channelIndex) const
{
    return String(channelIndex + 1);
}

bool GainPluginAudioProcessor::isInputChannelStereoPair(int index) const
{
    return true;
}

bool GainPluginAudioProcessor::isOutputChannelStereoPair(int index) const
{
    return true;
}


bool GainPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool GainPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double GainPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int GainPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int GainPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void GainPluginAudioProcessor::setCurrentProgram (int index)
{
}

const String GainPluginAudioProcessor::getProgramName (int index)
{
    return String();
}

void GainPluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void GainPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void GainPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool GainPluginAudioProcessor::setPreferredBusArrangement (bool isInput, int bus, const AudioChannelSet& preferredSet)
{
    // Reject any bus arrangements that are not compatible with your plugin

    const int numChannels = preferredSet.size();

   #if JucePlugin_IsMidiEffect
    if (numChannels != 0)
        return false;
   #elif JucePlugin_IsSynth
    if (isInput || (numChannels != 1 && numChannels != 2))
        return false;
   #else
    if (numChannels != 1 && numChannels != 2)
        return false;

    if (! AudioProcessor::setPreferredBusArrangement (! isInput, bus, preferredSet))
        return false;
   #endif

    return AudioProcessor::setPreferredBusArrangement (isInput, bus, preferredSet);
}
#endif

void GainPluginAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    //stereo channel
    if(totalNumInputChannels == 2)
    {
        float* samples0 = buffer.getWritePointer(0);
        float* samples1 = buffer.getWritePointer(1);
        
        int numSamples = buffer.getNumSamples();
        
        while(numSamples>0)
        {
            *samples0++;
            *samples1++;
            
            numSamples--;
        }
    }
    
    //mono
    if(totalNumInputChannels == 1)
    {
        float* samples0 = buffer.getWritePointer(0);
        float* samples1 = buffer.getWritePointer(0);
        
        int numSamples = buffer.getNumSamples();
        
        while(numSamples>0)
        {
            *samples0++;
            *samples1++;
            
            numSamples--;
        }
    }
    
    for(int i=getTotalNumInputChannels(); i<getTotalNumOutputChannels(); i++){
        buffer.clear(i, 0, buffer.getNumSamples()); //causing noise
    }
    
    
}

//==============================================================================
bool GainPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* GainPluginAudioProcessor::createEditor()
{
    return new GainPluginAudioProcessorEditor (this);
}

//==============================================================================
void GainPluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void GainPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new GainPluginAudioProcessor();
}

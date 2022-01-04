/*
  ==============================================================================

    SynthSound.h
    Created: 4 Jan 2022 9:42:52pm
    Author:  DEEGAN ALDING

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class SynthSound : public juce::SynthesiserSound
{
public:
    bool appliesToNote (int midiNoteNumber) override { return true; }
    bool appliesToChannel (int midiChannel) override{ return true; }

};

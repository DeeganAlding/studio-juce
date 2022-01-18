/*
  ==============================================================================

    SynthVoice.h
    Created: 4 Jan 2022 9:42:21pm
    Author:  DEEGAN

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "SynthSound.h"

class SynthVoice : public juce::SynthesiserVoice
{
public:
    bool canPlaySound(juce::SynthesiserSound* sound) override;
    void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;
    void stopNote(float velocity, bool allowTailOff) override;
    void controllerMoved(int controllerNumber, int newcControllerValue) override;
    void pitchWheelMoved(int newPitchWheelValue) override;
    void prepareToPlay(double sampleRate, int samplesPerBlock, int outputChannels);
    void renderNextBlock(juce::AudioBuffer< float >& outputBuffer, int startSample, int numSamples) override;

private:
    // Sin Wave
//juce::dsp::Oscillator<float> osc{ [](float x) { return std::sin(x);} }; sin wave
// Saw Wave
//juce::dsp::Oscillator<float> osc{ [](float x) {return x / juce::MathConstants<float>::pi;}};
// Square Wave
    juce::dsp::Oscillator<float> osc{ [](float x) {return x < 0.0f ? -1.0f : 1.0f;} };
    juce::dsp::Gain<float> gain;
};

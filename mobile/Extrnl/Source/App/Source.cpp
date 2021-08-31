#include "Source.h"

Source::Source(int id, juce::String name) : id(id), name(name)
{
}

Source::Source(int id, juce::String name, int sampleRate, bool sampleRateConversion, int bitDepth, int bufferLength)
    : id(id),
      name(name),
      sampleRate(sampleRate),
      sampleRateConversion(sampleRateConversion),
      bitDepth(bitDepth),
      bufferLength(bufferLength)
{
}

Source::Source(Source &other)
{
    id = other.id;
    name = other.name;
    sampleRate = other.sampleRate;
    sampleRateConversion = other.sampleRateConversion;
    bitDepth = other.bitDepth;
    bufferLength = other.bufferLength;
}

Source::~Source()
{
}

int Source::getId()
{
    return id;
}

void Source::setId(int newId)
{
    id = newId;
}

juce::String Source::getName()
{
    return name;
}

void Source::setName(juce::String newName)
{
    name = newName;
}

int Source::getSampleRate()
{
    return sampleRate;
}

void Source::setSampleRate(int newSampleRate)
{
    sampleRate = newSampleRate;
}

bool Source::getSampleRateConversion()
{
    return sampleRateConversion;
}

void Source::setSampleRateConversion(bool newSampleRateConversion)
{
    sampleRateConversion = newSampleRateConversion;
}

int Source::getBitDepth()
{
    return bitDepth;
}

void Source::setBitDepth(int newBitDepth)
{
    bitDepth = newBitDepth;
}

int Source::getBufferLength()
{
    return bufferLength;
}

void Source::setBufferLength(int newBufferLength)
{
    bufferLength = newBufferLength;
}

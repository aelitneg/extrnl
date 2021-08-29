#include "Source.h"

Source::Source(int id, juce::String name) : id(id), name(name)
{
}

Source::Source(Source &other)
{
    id = other.id;
    name = other.name;
}

Source::~Source()
{
}

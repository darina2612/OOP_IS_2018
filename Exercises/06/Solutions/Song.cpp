#include "Song.h"

#include <cstring>

Song::Song() : length(0.0)
{
}

Song::Song(const char* name, const char* artist, const char* genre, float length)
{
    this->name = String(name);
    this->artist = String(artist);
    this->genre = String(genre);
    this->length = length;
}

void Song::setName(const String& newName)
{
    name = newName;
}

String Song::getName() const
{
    return name;
}

void Song::setArtist(const String& newArtist)
{
    artist = newArtist;
}

String Song::getArtist() const
{
    return artist;
}

void Song::setGenre(const String& newGenre)
{
    genre = newGenre;
}

String Song::getGenre() const
{
    return genre;
}

void Song::setLength(float newLength)
{
    length = newLength;
}

float Song::getLength() const
{
    return length;
}

bool Song::operator < (const Song& other) const
{
    return length < other.length;
}

bool Song::operator <= (const Song& other) const
{
    return length <= other.length;
}

bool Song::operator == (const Song& other) const
{
    return length == other.length;
}

bool Song::operator != (const Song& other) const
{
    return length != other.length;
}

bool Song::operator >= (const Song& other) const
{
    return length >= other.length;
}

bool Song::operator > (const Song& other) const
{
    return length > other.length;
}

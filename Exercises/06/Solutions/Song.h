#pragma once

#include "String.h"

class Song
{
    String name;
    String artist;
    String genre;
    float length;

public:
    Song();
    Song(const char* name, const char* artist, const char* genre, float length);

    void setName(const String& newName);
    String getName() const;

    void setArtist(const String& newArtist);
    String getArtist() const;

    void setGenre(const String& newGenre);
    String getGenre() const;

    void setLength(float newLength);
    float getLength() const;

    bool operator < (const Song& other) const;
    bool operator <= (const Song& other) const;
    bool operator == (const Song& other) const;
    bool operator != (const Song& other) const;
    bool operator >= (const Song& other) const;
    bool operator > (const Song& other) const;
};

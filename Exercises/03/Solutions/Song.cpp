#include "Song.h"

#include <cstring>

Song::Song()
{
    name = new char[1];
    name[0] = '\0';

    artist = new char[1];
    artist[0] = '\0';

    genre = new char[1];
    genre[0] = '\0';

    length = 0.0;
}

Song::Song(const char* name, const char* artist, const char* genre, float lenght)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->artist = new char[strlen(artist) + 1];
    strcpy(this->artist, artist);

    this->genre = new char[strlen(genre) + 1];
    strcpy(this->genre, genre);

    this->length = length;
}

Song::Song(const Song& other)
{
    copy(other);
}

Song& Song::operator = (const Song& other)
{
    if(this != &other)
    {
        freeMemory();
        copy(other);
    }

    return *this;
}

Song::~Song()
{
   freeMemory();
}

void Song::copy(const Song& other)
{
    name = new char[strlen(other.name)];
    strcpy(name, other.name);

    artist = new char[strlen(other.artist)];
    strcpy(artist, other.artist);

    genre = new char[strlen(other.genre)];
    strcpy(genre, other.genre);

    length = other.length;
}

void Song::freeMemory()
{
    delete[] name;
    delete[] artist;
    delete[] genre;
}

void Song::setName(const char* newName)
{
    if(name != nullptr)
    {
        delete[] name;
    }

    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}

char* Song::getName() const
{
    return name;
}

void Song::setArtist(const char* newArtist)
{
    if(artist != nullptr)
    {
        delete[] artist;
    }

    artist = new char[strlen(newArtist) + 1];
    strcpy(artist, newArtist);
}

char* Song::getArtist() const
{
    return artist;
}

void Song::setGenre(const char* newGenre)
{
    if(genre != nullptr)
    {
        delete[] genre;
    }

    genre = new char[strlen(newGenre) + 1];
    strcpy(genre, newGenre);
}

char* Song::getGenre() const
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

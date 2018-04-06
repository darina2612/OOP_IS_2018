#pragma once

class Song
{
    char* name;
    char* artist;
    char* genre;
    float length;

    void copy(const Song& other);
    void freeMemory();

public:
    Song();
    Song(const char* name, const char* artist, const char* genre, float lenght);

    Song(const Song& other);
    Song& operator = (const Song& other);

    ~Song();
    
    void setName(const char* newName);
    char* getName() const;

    void setArtist(const char* newArtist);
    char* getArtist() const;

    void setGenre(const char* newGenre);
    char* getGenre() const;

    void setLength(float newLength);
    float getLength() const;

    bool operator < (const Song& other) const;
    bool operator <= (const Song& other) const;
    bool operator == (const Song& other) const;
    bool operator != (const Song& other) const;
    bool operator >= (const Song& other) const;
    bool operator > (const Song& other) const;
};

#pragma once

#include "Song.h"
#include <cstdlib>

class MusicAlbum
{
    Song* songs;
    size_t currentNumberOfSongs;
    size_t songsCapacity;

    void copy(const MusicAlbum& other);
    void freeMemory();
    void resize(size_t newCapacity);

public:
    MusicAlbum();

    MusicAlbum(const MusicAlbum& other);
    MusicAlbum& operator=(const MusicAlbum& other);

    ~MusicAlbum();

    Song* getSongs() const;

    void addSong(Song song);
    void removeSongAtIndex(size_t index);

    double totalLength() const;

    size_t countOfSongsOfGenre(const char* genre) const;
    size_t countOfSongsOfArtist(const char* artistName) const;

    size_t indexOfShortestSong() const;
};

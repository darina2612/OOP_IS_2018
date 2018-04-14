#pragma once

#include "Song.h"
#include <cstdlib>
#include "Vector.h"

class MusicAlbum
{
    Vector<Song> songs;

public:
    Vector<Song> getSongs() const;

    void addSong(Song song);
    void removeSongAtIndex(size_t index);

    double totalLength() const;

    size_t countOfSongsOfGenre(const String &genre) const;
    size_t countOfSongsOfArtist(const String& artistName) const;

    size_t indexOfShortestSong() const;
};

#include "MusicAlbum.h"

#include <cstring>
#include <cassert>


Vector<Song> MusicAlbum::getSongs() const
{
    return songs;
}

void MusicAlbum::addSong(Song song)
{
    songs.push_back(song);
}

void MusicAlbum::removeSongAtIndex(size_t index)
{
    songs.removeElementAtIndex(index);
}

double MusicAlbum::totalLength() const
{
    float totalLenght = 0.0;
    size_t songsCount = songs.size();

    for(size_t i = 0; i < songsCount; ++i)
    {
        totalLenght += songs[i].getLength();
    }

    return totalLenght;
}

size_t MusicAlbum::countOfSongsOfGenre(const String& genre) const
{
    size_t songsOfGenre = 0;
    size_t songsCount = songs.size();

    for(size_t i = 0; i < songsCount; ++i)
    {
        if(songs[i].getGenre() == genre)
        {
            ++songsOfGenre;
        }
    }

    return songsOfGenre;
}

size_t MusicAlbum::countOfSongsOfArtist(const String &artistName) const
{
    size_t songsOfArtist = 0;
    size_t songsCount = songs.size();

    for(size_t i = 0; i < songsCount; ++i)
    {
        if(songs[i].getArtist() == artistName)
        {
            ++songsOfArtist;
        }
    }

    return songsOfArtist;
}

size_t MusicAlbum::indexOfShortestSong() const
{
    size_t indexOfShortest = 0;
    size_t songsCount = songs.size();

    for(size_t i = 0; i < songsCount; ++i)
    {
        if(songs[i].getLength() < songs[indexOfShortest].getLength())
        {
            indexOfShortest = i;
        }
    }

    return indexOfShortest;
}

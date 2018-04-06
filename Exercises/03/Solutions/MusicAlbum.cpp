#include "MusicAlbum.h"

#include <cstring>
#include <cassert>

MusicAlbum::MusicAlbum()
{
    songsCapacity = 1;
    songs = new Song[songsCapacity];
    currentNumberOfSongs =  0;
}

MusicAlbum::MusicAlbum(const MusicAlbum& other)
{
    copy(other);
}

MusicAlbum& MusicAlbum::operator=(const MusicAlbum& other)
{
    if(this != &other)
    {
        freeMemory();
        copy(other);
    }

    return *this;
}

MusicAlbum::~MusicAlbum()
{
    freeMemory();
}

Song* MusicAlbum::getSongs() const
{
    return songs;
}

void MusicAlbum::copy(const MusicAlbum& other)
{
    songsCapacity = other.songsCapacity;
    currentNumberOfSongs = other.currentNumberOfSongs;

    songs = new Song[songsCapacity];

    for(size_t i = 0; i < currentNumberOfSongs; ++i)
    {
        songs[i] = other.songs[i];
    }
}

void MusicAlbum::freeMemory()
{
    delete [] songs;
}

void MusicAlbum::resize(size_t newCapacity)
{
    assert(newCapacity >= currentNumberOfSongs);

    songsCapacity = newCapacity;

    Song* temp = new Song[songsCapacity];

    for(size_t i = 0; i < currentNumberOfSongs; ++i)
    {
        temp[i] = songs[i];
    }

    delete [] songs;
    songs = temp;
}

void MusicAlbum::addSong(Song song)
{
    if(songsCapacity >= currentNumberOfSongs)
    {
        resize(songsCapacity * 2);
    }

    songs[currentNumberOfSongs++] = song;
}

void MusicAlbum::removeSongAtIndex(size_t index)
{
    for(size_t i = index; i < currentNumberOfSongs - 1; ++i)
    {
        songs[i] = songs[i + 1];
    }

    --currentNumberOfSongs;
}

double MusicAlbum::totalLength() const
{
    float totalLenght = 0.0;

    for(size_t i = 0; i < currentNumberOfSongs; ++i)
    {
        totalLenght += songs[i].getLength();
    }

    return totalLenght;
}

size_t MusicAlbum::countOfSongsOfGenre(const char* genre) const
{
    size_t songsOfGenre = 0;

    for(size_t i = 0; i < currentNumberOfSongs; ++i)
    {
        if(strcmp(songs[i].getGenre(), genre) == 0)
        {
            ++songsOfGenre;
        }
    }

    return songsOfGenre;
}

size_t MusicAlbum::countOfSongsOfArtist(const char* artistName) const
{
    size_t songsOfArtist = 0;

    for(size_t i = 0; i < currentNumberOfSongs; ++i)
    {
        if(strcmp(songs[i].getArtist(), artistName) == 0)
        {
            ++songsOfArtist;
        }
    }

    return songsOfArtist;
}

size_t MusicAlbum::indexOfShortestSong() const
{
    int indexOfShortest = 0;

    for(size_t i = 0; i < currentNumberOfSongs; ++i)
    {
        if(songs[i].getLength() < songs[indexOfShortest].getLength())
        {
            indexOfShortest = i;
        }
    }

    return indexOfShortest;
}

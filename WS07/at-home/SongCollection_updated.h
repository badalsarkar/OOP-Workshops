#define _CRT_SECURE_NO_WARNINGS

#ifndef SDDS_SONGCOLLECTION_H
#define SDDS_SONGCOLLECTION_H

#include <vector>
#include <list>

namespace sdds{
    //define a structure
    //this structure holds information about a single song 
    typedef struct {
        std::string title,
            artist,
            album,
            year;
        double m_price;
        int length;
    } Song;




    //class declaration
    //this class manages a collection of type Song
    class SongCollection{
        std::vector<Song> song_collection;
    public:
        SongCollection(const char* file);
        void display(std::ostream& out)const;
        void sort(std::string param);
        void cleanAlbum();
        bool inCollection(std::string artistName)const;
        std::list<Song> getSongsForArtist(std::string artistName)const;
    };



    //free helper
    std::string trim(std::string text);
    std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif

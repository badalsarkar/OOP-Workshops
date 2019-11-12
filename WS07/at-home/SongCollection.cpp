#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include "SongCollection.h"


namespace sdds{
    /*
       custom constructor
       1. reads the file line by line
       2. if lines contain valid data, stores into 
            data member
       3. Acceptable format: TITLE ARTIST ALBUM YEAR LENGTH PRICE
       4. Title, artist and album has 25 chars, year, length and price
          has 5 chars
       5. throws exception if the file is not valid
    */

    SongCollection::SongCollection(const char* file){
        //todo:validate the file name
        std::ifstream sourceFile(file);
        if(sourceFile){
            //create temporary variable
            std::string temp_artist, temp_title, temp_album,temp_year,line;
            double temp_price;
            int temp_songLength;
            size_t pos,len;
            while (sourceFile){
                pos=0;
                len=25;
                //read one line from the file
                std::getline(sourceFile, line); 
                try{
                    trim(line);
                    // extract the data
                    temp_title=trim(line.substr(pos,len));
                    pos+=len;
                    temp_artist=trim(line.substr(pos,len));
                    pos+=len;
                    temp_album=trim(line.substr(pos,len));
                    pos+=len;
                    len=5;
                    //convert string to number
                    //the conversion may generate exception
                    //if there is exception thrown, ignore all the input 
                    //move to next line
                    //if no exception create object and add to vector
                    temp_year=line.substr(pos,len);
                    temp_year=trim(temp_year);
                    pos+=len;
                    temp_songLength=std::stoi(trim(line.substr(pos,len)));
                    pos+=len;
                    temp_price=std::stod(trim(line.substr(pos,len)));
                    //todo: create a Song object with data
                    Song tempSong={
                        title:temp_title,
                        artist:temp_artist,
                        album:temp_album,
                        year:temp_year,
                        m_price:temp_price,
                        length:temp_songLength
                    };
                    //todo: add the object into the vector
                    song_collection.push_back(tempSong);
                }
                catch(...){
                    //empty
                }
                temp_title="";
                temp_artist="";
                temp_album="";
                temp_year="";
                temp_price=0;
                temp_songLength=0;
                line="";
            } //end of while loop
            //clear error if any and close the file
            sourceFile.clear();
            sourceFile.close();
        }
        else{
            //todo: if file name is invalid, throw error 
            throw "Invalid file name";
        }
        
    }



    /*
       sort function
       this function sorts the song_collection vector
       it receives as parameter the key to sort
       it sorts in ascending order
    */
    void SongCollection::sort(std::string param){
        std::sort(song_collection.begin(), song_collection.end(),[&](Song i, Song j){
                bool result;
                if(param=="title")
                    result=i.title<j.title;
                if(param=="album")
                    result=i.album<j.album;
                if(param=="length")
                    result=i.length<j.length;
                return result;
                }
        );
    }



    /*
       this function removes [none] from album field
   */
    void SongCollection::cleanAlbum(){
    std::for_each(song_collection.begin(), song_collection.end(), [](Song& i){
            if(i.album=="[None]")
                i.album="";
                }
            );
    }




    /*
       this function searches for the parameter value in artist column
       returns true if found, otherwise false
   */
    bool SongCollection::inCollection(std::string artistName)const{
        std::vector<Song>::iterator iter;
        std::find_if(song_collection.begin(),song_collection.end(),[&](Song i){
                return i.artist==artistName;
                });

        return (iter==song_collection.end()?false:true);
    }



    /*
       this function finds all the songs by the artist in the parameter
       it returns a list of all the songs
   */
    std::list<Song> SongCollection::getSongsForArtist(std::string artistName)const{
        std::list<Song> songList(song_collection.size());
        auto pos=std::copy_if(song_collection.begin(), song_collection.end(), songList.begin(),[&](Song i){
               return i.artist==artistName;
               });
        songList.resize(std::distance(songList.begin(),pos));
        return songList;
    }




    /*
       display function
       this function displays all items of the SongCollection vector
    */
    void SongCollection::display(std::ostream& out)const{
        int totalPlayTime=0;
        std::for_each(song_collection.begin(), song_collection.end(),[&](const Song& theSong){
               out<<theSong<<std::endl;
               totalPlayTime+=theSong.length;
               });
        out<<std::setw(89)<<std::setfill('-')<<'\n'<<std::setfill(' ');
        out<<"| "<<std::right<<std::setw(77)<<"Total Listening Time: "<<totalPlayTime/(60*60)<<":"<<(totalPlayTime%(60*60))/60<<":"<<totalPlayTime%60<<" |"<<std::endl;
    }



    /*
       trim function
       1. this function receives a reference to a string
       2. it removes all leading and tailing spaces from ths string
   */
    std::string trim(std::string text){
        try{
            size_t startPos=text.find_first_not_of(' ');
            size_t endPos=text.find_last_not_of(' ');
            text=text.substr(startPos,((endPos-startPos)+1));
        }catch(...){
            //empty
        };
        return text;
    }




    /*
       overloaded << operator
    */
    std::ostream& operator<<(std::ostream& out, const Song& theSong){
        out<<"| "<<std::setw(20)<<std::left<<theSong.title<<" | "
            <<std::setw(15)<<std::left<<theSong.artist<<" | "
            <<std::setw(20)<<std::left<<theSong.album<<" | "
            <<std::setw(6)<<std::right<<theSong.year<<" | "
            <<std::right<<(theSong.length)/60<<":"
            <<std::setfill('0')<<std::setw(2)<<theSong.length%60<<" | "
            <<std::setfill(' ')
            <<std::right<<theSong.m_price<<" | ";
        return out;
    }

} //end of namespace

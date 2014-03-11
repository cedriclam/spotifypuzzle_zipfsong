//
//  Album.h
//  SpotifyPuzzle_zipfsong
//
//  Created by Cedric Lamoriniere on 7/11/13.
//  Copyright (c) 2013 Cedric Lamoriniere. All rights reserved.
//

#ifndef __SpotifyPuzzle_zipfsong__Album__
#define __SpotifyPuzzle_zipfsong__Album__

#include <iostream>
#include <list>
#include <set>
#include <map>

typedef std::map<int,std::list<std::string> > SONGMAPBYQUALITY;
typedef std::list<std::string> SONGLIST;

namespace model {
    class Album{
    public:
        Album();
        virtual ~Album(){};
        
        void setNumberOfSong(const int& nbSong);
        void addSong(const int&iQuality, const std::string& iTitle);
        std::list<std::string> selectNBestSong(const int &iNumber);
    
    private:
        SONGMAPBYQUALITY _SongByQuality;
        SONGLIST _SongList;
        
        int _nbSong;
    };
}

#endif /* defined(__SpotifyPuzzle_zipfsong__Album__) */

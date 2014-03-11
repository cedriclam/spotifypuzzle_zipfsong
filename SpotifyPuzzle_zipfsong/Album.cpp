//
//  Album.cpp
//  SpotifyPuzzle_zipfsong
//
//  Created by Cedric Lamoriniere on 7/11/13.
//  Copyright (c) 2013 Cedric Lamoriniere. All rights reserved.
//

#include "Album.h"

namespace model {
    Album::Album(): _nbSong (0){}
    
    void Album::setNumberOfSong(const int &nbSong){
        _nbSong = nbSong;
    }
    
    void Album::addSong(const int&iRead, const std::string& iTitle)
    {
        int size = (int)_SongList.size();
        int iQuality = iRead / (_nbSong - size);
        _SongByQuality[iQuality].push_front(iTitle);
        _SongList.push_back(iTitle);
    }
    
    std::list<std::string> Album::selectNBestSong(const int &iNumber)
    {
        std::list<std::string> output;
        std::set<std::string> selection;
        
        int counter = 0;
        SONGMAPBYQUALITY::reverse_iterator rIter;
        for (rIter = _SongByQuality.rbegin();
             (rIter != _SongByQuality.rend()) && (counter < iNumber);
             ++rIter)
        {
            const std::list<std::string>& aList = rIter->second;
            if (aList.begin() != aList.end())
            {
                selection.insert(aList.front());
                ++counter;
            }
        }
        
        SONGLIST::reverse_iterator iterMap;
        for (iterMap = _SongList.rbegin(); iterMap != _SongList.rend(); ++iterMap)
        {
            if (selection.find(*iterMap) != selection.end())
            {
                output.push_back(*iterMap);
            }
        }
        
        return output;
    }

}
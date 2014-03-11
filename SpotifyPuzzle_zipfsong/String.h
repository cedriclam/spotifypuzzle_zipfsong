//
//  String.h
//  SpotifyPuzzle_zipfsong
//
//  Created by Cedric Lamoriniere on 7/11/13.
//  Copyright (c) 2013 Cedric Lamoriniere. All rights reserved.
//

#ifndef __SpotifyPuzzle_zipfsong__String__
#define __SpotifyPuzzle_zipfsong__String__

#include <iostream>

#include <string>
#include <vector>

namespace tools{
    class String: public std::string{
    public:
        String(){};
        String(char *s);
        virtual ~String(){};
        
        std::vector<std::string> split(char delim,int rep = 0);
    };
}
#endif /* defined(__SpotifyPuzzle_zipfsong__String__) */

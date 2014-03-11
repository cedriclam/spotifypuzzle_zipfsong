//
//  String.cpp
//  SpotifyPuzzle_zipfsong
//
//  Created by Cedric Lamoriniere on 7/11/13.
//  Copyright (c) 2013 Cedric Lamoriniere. All rights reserved.
//

#include "String.h"

namespace tools{
    String::String(char *s): std::string(s) { };
    
    std::vector<std::string> String::split(char delim, int rep)
    {
        std::vector<std::string> output;
        
        std::string work = data();
        std::string buf = "";
        int i = 0;
        while (i < work.length()) {
            if (work[i] != delim)
                buf += work[i];
            else if (rep == 1) {
                output.push_back(buf);
                buf = "";
            } else if (buf.length() > 0) {
                output.push_back(buf);
                buf = "";
            }
            i++;
        }
        if (!buf.empty())
            output.push_back(buf);
        
        return output;
    }
}
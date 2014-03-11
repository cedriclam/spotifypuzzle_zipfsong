#include <iostream>
#include <vector>

#include "String.h"

#include "Album.h"


int main(int argc, const char * argv[])
{
    tools::String input;

    // retrieve the first line this the number of song and the number a selected song
    try{
        getline(std::cin,input);
    }
    catch(...){
         std::cout << "Error: with first line read";
    }
    
    if (input.size() == 0){
        std::cout << "Error: no input!";
        return 0;
    }

    std::vector<std::string> results = input.split(' ');
    if (results.size() != 2)
    {
        std::cout << "Error: first line not valid!";
        return 1;
    }
    
    const int nbSong = atoi(results.front().c_str());         // Number of song present
    const int nbSelectedSong = atoi(results.back().c_str());  // Number of requested song
    
    // Create the Album object that will store all the information
    model::Album aAblum;
    aAblum.setNumberOfSong(nbSong);
    
    // start to retrieve the information songs
    for (int i = 0; i < nbSong; ++i)
    {
        getline(std::cin,input);
        results = input.split(' ');
        if (results.size() != 2)
        {
            std::cout << "Error: line: " << i << " is invalid, data:"<< input << "\n";            
        }
        aAblum.addSong(atoi(results.front().c_str()),results.back());
    }
    
    std::list<std::string> ouputList = aAblum.selectNBestSong(nbSelectedSong);
    for (auto& iter : ouputList)
    {
        std::cout << iter << "\n";
    }
    
    return 0;
}

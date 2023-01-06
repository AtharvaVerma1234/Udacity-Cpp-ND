#ifndef ADDITIONAL_FEATURE_H
#define ADDITIONAL_FEATURE_H

#include "SDL.h"
#include <string>
#include <iostream>

class AdditionalFeature
{
public:
    AdditionalFeature():OSUsed(std::string())
    { OSUsed = getOS(); }
    
    /**
     * Sets the user's operating system to the private variable OSUsed.
     * Returns the user's operating system as a std::string.
     */
    std::string getOS();
    void printOS();

private:
    std::string OSUsed;
};


#endif
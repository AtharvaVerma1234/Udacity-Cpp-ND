#include "additional_feature.h"


std::string AdditionalFeature::AdditionalFeature::getOS()
{
    const char *OS = SDL_GetPlatform();
    std::string p(OS);
    OSUsed = p;
    return OSUsed;
};

void AdditionalFeature::AdditionalFeature::printOS()
{
 
    if (OSUsed != "")
        std::cout << "     OS Detected: " << OSUsed << std::endl;
    else
        std::cout << "Unable to detect the Operating System" << std::endl;
}

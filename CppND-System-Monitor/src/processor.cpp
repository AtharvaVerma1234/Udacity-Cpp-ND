#include "processor.h"
#include <string>
#include <vector>
// TODO: Return the aggregate CPU utilization
float Processor::Utilization() 
{
  std::vector<std::string> jiffies = LinuxParser::CpuUtilization();
  //The size of string vector will be 10 as there are 10 cols in the first row /proc/stat file and we only read the first row in this project.
  for (long int i=0; i<10;i++)
  {
    //in linux_parser.h the enums are declared with first element as 0. So the rest will be //implicitly initialized as 1,2,3...9 respectively.
    //We can also use integers in place of enums.
    if (i!=LinuxParser::kGuest_ and i!=LinuxParser::kGuestNice_){
    	TJiffies += std::stof(jiffies[i]);
    }
    if (i==LinuxParser::kIdle_ or i==LinuxParser::kIOwait_){
    	IJiffies += std::stof(jiffies[i]);
    }
  }
  long UJiffies = TJiffies - IJiffies;
  
    usage = (double)(UJiffies)/(TJiffies);
  return usage; 
}
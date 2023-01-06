#include <string>

#include "format.h"

using std::string;


// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS

string Format::ElapsedTime(long secs)
{
  long Hrs=secs/3600;
  long Hrs_remainder=secs%3600;
  long Minutes=Hrs_remainder/60;
  long Seconds=Hrs_remainder%60;
  string Secs_str;
  string Mins_str;
  string Hrs_str;
  if(Hrs>9)
  {
  Hrs_str=std::to_string(Hrs);
  }
  else
  {Hrs_str="0"+std::to_string(Hrs);}
    
  if (Minutes>9)
  {
  Mins_str=std::to_string(Minutes);
  }
  else
  {Mins_str="0"+std::to_string(Minutes);}
  if(Seconds>9)
  {
  Secs_str=std::to_string(Seconds);
  }
  else
  {Secs_str="0"+std::to_string(Seconds);}
  string TIME=Hrs_str+':'+Mins_str+':'+Secs_str;
  return TIME; 
}
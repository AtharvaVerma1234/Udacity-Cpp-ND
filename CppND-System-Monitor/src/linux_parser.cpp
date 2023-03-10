#include <dirent.h>
#include <unistd.h>
#include <string>
#include <vector>
#include <iostream>
#include "linux_parser.h"

using std::stof;
using std::string;
using std::to_string;
using std::vector;

// DONE: An example of how to read data from the filesystem
string LinuxParser::OperatingSystem() {
  string line;
  string key;
  string value;
  std::ifstream filestream(kOSPath);
  if (filestream.is_open()) {
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.end(), ' ', '_');
      std::replace(line.begin(), line.end(), '=', ' ');
      std::replace(line.begin(), line.end(), '"', ' ');
      std::istringstream linestream(line);
      while (linestream >> key >> value) {
        if (key == "PRETTY_NAME") {
          std::replace(value.begin(), value.end(), '_', ' ');
          return value;
        }
      }
    }
  }
  return value;
}

// DONE: An example of how to read data from the filesystem
string LinuxParser::Kernel() {
  string os, kernel,version;
  string line;
  std::ifstream stream(kProcDirectory + kVersionFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    linestream >> os >> version>>kernel;
  }
  return kernel;
}

// BONUS: Update this to use std::filesystem
vector<int> LinuxParser::Pids() {
  vector<int> pids;
  DIR* directory = opendir(kProcDirectory.c_str());
  struct dirent* file;
  while ((file = readdir(directory)) != nullptr) {
    // Is this a directory?
    if (file->d_type == DT_DIR) {
      // Is every character of the name a digit?
      string filename(file->d_name);
      if (std::all_of(filename.begin(), filename.end(), isdigit)) {
        int pid = stoi(filename);
        pids.push_back(pid);
      }
    }
  }
  closedir(directory);
  return pids;
}

// TODO: Read and return the system memory utilization
float LinuxParser::MemoryUtilization() 
{
  float TotalMem, FreeMem;
  string key, value, kb, line;
  std:: ifstream stream(kProcDirectory + kMeminfoFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)){
      	std::replace(line.begin(), line.end(), ':', ' ');
  		std::istringstream linestream(line);
    	while (linestream >> key >> value >> kb) {
        	if (key == "MemTotal")
            {
              TotalMem = std::stof(value);
            }
            if (key == "MemFree") 
            { 
              FreeMem = std::stof(value);}
        	}
    	}
  }
  return (TotalMem-FreeMem)/TotalMem; 
}

// TODO: Read and return the system uptime
long LinuxParser::UpTime() 
{ 
  long uptime_;
  string uptime, idletime, line;
  std::ifstream stream(kProcDirectory + kUptimeFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
  	std::istringstream linestream(line);
    linestream >> uptime >> idletime;
    uptime_ = std::stol(uptime);
    }
  return uptime_; 
}

// TODO: Read and return the number of jiffies for the system
long LinuxParser::Jiffies() 
{
  string line, val;
  vector <string> stats;
  std::ifstream stream(kProcDirectory+kStatFilename);
  if(stream.is_open())
  {
	std::getline(stream,line);
    std::istringstream linestream(line);
    while(linestream >> val)
    {
      stats.emplace_back(val);
    }
    
  }
  long int user{std::stol(stats[1])};
  long int nice{std::stol(stats[2])};
  long int system{std::stol(stats[3])};
  long int idle{std::stol(stats[4])};
  long int iowait{std::stol(stats[5])};
  long int irq{std::stol(stats[6])};
  long int softirq{std::stol(stats[7])};
  long int steal{std::stol(stats[8])};
  long int guest{std::stol(stats[9])};
  long int guest_nice{std::stol(stats[10])};
  return user+nice+system+idle+iowait+irq+softirq+steal+guest+guest_nice; 
}

// TODO: Read and return the number of active jiffies for a PID
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::ActiveJiffies(int pid) 
{ 
  string value, line;
  long total_active_jiffies;
  vector<string> stat_list;
  std::ifstream str(kProcDirectory + std::to_string(pid) + kStatFilename);
  if (str.is_open())
  {
    std::getline(str, line);
    std::istringstream linestr(line);
    while (linestr >> value) 
    {
			stat_list.emplace_back(value);
        }
    }
  long int usertime{std::stol(stat_list[13])};
  long int kerneltime{std::stol(stat_list[14])};
 //I did not include the children time which can be accessed as stat_list[15] and //stat_list[16]
  total_active_jiffies = (usertime + kerneltime);
  return total_active_jiffies;
   
}

// TODO: Read and return the number of active jiffies for the system
long LinuxParser::ActiveJiffies() 
{ 
 return LinuxParser::Jiffies()-LinuxParser::IdleJiffies();
  
}

// TODO: Read and return the number of idle jiffies for the system
long LinuxParser::IdleJiffies() 
{
  string line, val;
  vector <string> stats;
  std::ifstream stream(kProcDirectory+kStatFilename);
  if(stream.is_open())
  {
	std::getline(stream,line);
    std::istringstream linestream(line);
    while(linestream >> val)
    {
      stats.emplace_back(val);
    }
    
  }
  
  long int idle{std::stol(stats[4])};
  long int iowait{std::stol(stats[5])};
  return idle+iowait; 

}

// TODO: Read and return CPU utilization
vector<string> LinuxParser::CpuUtilization() 
{
  string value, line, key;
  vector<string> jiffies_;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
  	std::istringstream linestream(line);
   	while (linestream >> key){
    	if (key != "cpu"){
          jiffies_.emplace_back(key);}
    }
    }
  return jiffies_;
  
 } 

// TODO: Read and return the total number of processes
int LinuxParser::TotalProcesses() 
{ 
	int val;
  string key, value, line;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) 
  {
    while (std::getline(stream, line))
    {
  		std::istringstream linestream(line);
    	while (linestream >> key >> value) 
      {
        	if (key == "processes") 
          { 
              val = std::stoi(value);
              return val;
              }
        	}
      	}
    }
  return 0; 
}

// TODO: Read and return the number of running processes
int LinuxParser::RunningProcesses() 
{ 
	int val;
  string key, value, line;
  std::ifstream stream(kProcDirectory + kStatFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)){
  		std::istringstream linestream(line);
    	while (linestream >> key >> value) {

        	if (key == "procs_running") { 
              val = std::stoi(value);
              return val;

              }
        	}
      	}
    }
  return 0;
}

// TODO: Read and return the command associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Command(int pid) 
{ 
	string command, line;
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kCmdlineFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)){
  		std::istringstream linestream(line);
      	std::replace(line.begin(), line.end(), ' ', '*');
    	while (linestream >> command) {
			std::replace(command.begin(), command.end(), '*', ' ');
          	
        }
      }
    }
  return command;
}

// TODO: Read and return the memory used by a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Ram(int pid) 
{ 
  string key, value, size_unit, line;
  long int Ram_Usage;
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatusFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)){
  		std::istringstream linestream(line);
    	while (linestream >> key >> value>>size_unit ) {
        	if (key == "VmSize:") { 
              	Ram_Usage = std::stol(value); 
              //to convert Ram Usage from KB to MB
              	Ram_Usage = Ram_Usage/1024;
              	return std::to_string(Ram_Usage);
               }
        	}
      	}
    }
  return "Error Returning Ram Usage of "+std::to_string(pid); 
}

// TODO: Read and return the user ID associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::Uid(int pid) 
{ 
  string key,  uid, line;
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatusFilename);
  if (stream.is_open()) {
    while (std::getline(stream, line)){
  		std::istringstream linestream(line);
    	while (linestream >> key >> uid) {
        	if (key == "Uid:") { 
              	return uid;
               }
        	}
      	}
    }
  return "Error Returning UID of "+std::to_string(pid);
}

// TODO: Read and return the user associated with a process
// REMOVE: [[maybe_unused]] once you define the function
string LinuxParser::User(int pid) 
{ 
  string s, line;
  string uid_ = LinuxParser::Uid(pid);
  std::ifstream stream(kPasswordPath);
  if (stream.is_open()) {
    while (std::getline(stream, line)){
        std::replace(line.begin(), line.end(), ':', ' ');
      std::istringstream linestream(line);
      vector<string > s1;
    	while (linestream >> s) 
        {
            	s1.emplace_back(s);   
        	}
      if (s1[2]==uid_){
                return s1[0];
         }
      	}
    }
  return "Error in returning user of "+std::to_string(pid);
}

// TODO: Read and return the uptime of a process
// REMOVE: [[maybe_unused]] once you define the function
long LinuxParser::UpTime(int pid) 
{ 
   string value, line;
  long int starttime, uptime;
  vector<string> stat_list;
  std::ifstream stream(kProcDirectory + std::to_string(pid) + kStatFilename);
  if (stream.is_open()) {
    std::getline(stream, line);
    std::istringstream linestream(line);
    while (linestream >> value) {
			stat_list.emplace_back(value);
        }
    }
  // sysconf(_SC_CLK_TCK) gives the size of a jiffy in Hz(It may be different for different kernel)
  starttime = std::stol(stat_list[21])/sysconf(_SC_CLK_TCK);
  uptime =  LinuxParser::UpTime() - starttime;
  return uptime;
}
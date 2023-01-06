#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;
Process::Process(int pid) {
  PID = pid;
  _cpu_util = Process::CpuUtilization();
  CMD = LinuxParser::Command(PID);
}
// TODO: Return this process's ID
int Process::Pid() { return PID; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() 
{ 
  
   _total_time = LinuxParser::ActiveJiffies(PID)/ sysconf(_SC_CLK_TCK); 
  _seconds = LinuxParser::UpTime(PID);
  return _total_time/_seconds;
}

// TODO: Return the command that generated this process
string Process::Command() { return CMD; }

// TODO: Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(PID); }

// TODO: Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(PID); }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(PID); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const 
{ return _cpu_util>a._cpu_util; }
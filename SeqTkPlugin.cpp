#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "SeqTkPlugin.h"

void SeqTkPlugin::input(std::string file) {
 inputfile = file;
 std::ifstream ifile(inputfile.c_str(), std::ios::in);
 std::cout << file << std::endl;
 while (!ifile.eof()) {
   std::string key, value;
   ifile >> key;
   if (key.length() == 0) break;
   ifile >> value;
   if (value.length() == 0) break;
   parameters[key] = value;
 }

}

void SeqTkPlugin::run() {}

void SeqTkPlugin::output(std::string file) {
 std::string outputfile = file;
 std::string myCommand = "";
myCommand +=  "seqtk sample";
myCommand += " ";
myCommand += "-s";
myCommand += parameters["seed"] + " ";
myCommand += std::string(PluginManager::prefix())+parameters["fastq"];
myCommand += " ";
myCommand += parameters["frac"] + " > ";
myCommand += outputfile;
std::cout << myCommand << std::endl;
system(myCommand.c_str());
}

PluginProxy<SeqTkPlugin> SeqTkPluginProxy = PluginProxy<SeqTkPlugin>("SeqTk", PluginManager::getInstance());

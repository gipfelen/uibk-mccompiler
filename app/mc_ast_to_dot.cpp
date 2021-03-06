#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>

#include "mcc/mcc.hpp"
#include "../app/include/ArgumentParser.hpp"
#include "../app/include/MCCCommon.hpp"

using namespace MC;

void printHelpMessage(){
  std::cout << "usage: mc_ast_to_dot [OPTIONS] file\n"
  "Utility for printing an abstract syntax tree in the DOT format.\n"
  "The output can be visualised using graphviz. Errors are reported on invalid inputs.\n"
  "Use '-' as input file to read from stdin.\n\n"
  "OPTIONS:\n"
  "-h, --help                displays this help message\n"
  "-o, --output <file>       write the output to <file> (defaults to stdout)\n"
  "-f, --function <name>     limit scope to the given function\n"
   << std::endl;
}

int main( const int argc, const char **argv ){
  ArgumentParser arg(argc, argv);

  //If no input is provieded or the -h flag, print help
  if( argc <= 1 || arg.cmdOptionExists("-h")){
    printHelpMessage();
    return ( EXIT_SUCCESS );
  }

  MC::MCC mcc;
  try{
    int cntInFiles = arg.numberOfFiles({"-h", "-o", "-f"});
    for (int i = cntInFiles; i>0; i--){
      mcc.parse( argv[argc - i]);
    }
    std::string dot = arg.cmdOptionExists("-f") ? mcc.getAsDot(arg.getCmdOption("-f")) : mcc.getAsDot();

    if (!arg.cmdOptionExists("-o")){
      std::cout << "\n\n"<< dot << "\n\n";
    }else{
      writeToFile(arg.getCmdOption("-o"), dot);
    }

  }catch (char const* msg){
    std::cout << msg << std::endl;
    return EXIT_FAILURE;
  }

  return( EXIT_SUCCESS );
}

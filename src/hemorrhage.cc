/*! \file hemorrhage.cc
	Main application interface for hemorrhage
*/

#include <string>
#include <iostream>

#include <llvm/Support/CommandLine.h>

using namespace llvm::cl;

opt<std::string> InputFilename(Positional, Required, desc("<input file>"));
opt<std::string> OutputFilename("o", value_desc("filename"), desc("Specify output filename"));

int main(int argc, char* argv[]) {
	ParseCommandLineOptions(argc, argv);


}

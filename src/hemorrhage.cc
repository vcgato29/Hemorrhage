/*! \file hemorrhage.cc
	Main application interface for hemorrhage
*/

#include <string>
#include <iostream>

#include <llvm/Support/CommandLine.h>
#include <clang-c/Index.h>
using namespace llvm::cl;

opt<std::string> InputFilename(Positional, Required, desc("<input file>"));
opt<std::string> OutputFilename("o", value_desc("filename"), desc("Specify output filename"));
opt<bool> Version("hemorrhage-version", desc("Display the current program version"));

int main(int argc, char* argv[]) {
	ParseCommandLineOptions(argc, argv);
	if(Version) {
		std::cout << "Hemorrhage v" << VERSION_STRING << std::endl;
		return 0;
	}

	CXIndex Index = clang_createIndex(0, 0);
	CXTranslationUnit TU =  clang_parseTranslationUnit(Index, 0, argv, argc, 0, 0, CXTranslationUnit_None);

	std::cout << "Translating " << InputFilename.c_str() << std::endl;

	for (unsigned I = 0, N = clang_getNumDiagnostics(TU); I != N; ++I) {
		CXDiagnostic Diag = clang_getDiagnostic(TU, I);
		CXString String = clang_formatDiagnostic(Diag,
		clang_defaultDiagnosticDisplayOptions());
		std::cerr << clang_getCString(String) << std::endl;
		clang_disposeString(String);
	}

	InputFilename

	clang_disposeTranslationUnit(TU);
	clang_disposeIndex(Index);
	return 0;
}

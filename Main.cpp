#include <iostream>
#include "Translator.h"

int main(int argc, char* argv[]){

	std::cout << "Please Enter input filename: \n";
	
	std::string filename;
	std::cin >> filename;

	Translator translator;

	if(translator.loadmRNAFromFile(filename) != 0)
		return 0;

	translator.translate();

	std::cout << "Please Enter Output filename: \n";
	
	std::string outputFilename;
	std::cin >> outputFilename;

	translator.saveToFile(outputFilename);
	return 0;
}

#include <iostream>
#include "Translator.h"

std::string menu = 
"+-------------------+\n"
"|  mRNA Translator  |\n"
"|[1] Read from File |\n"
"|[2] Read from STDIN|\n"
"|[3] Quit           |\n"
"+-------------------+\n";

Translator inputFile () {
std::cout << "Please Enter input filename: \n";
	
	std::string filename;
	std::cin >> filename;

	Translator translator;

	if(translator.loadmRNAFromFile(filename) != 0)
		return 0;

	translator.translate();
	return translator;
}

Translator STDIN() {
	std::string mrna;
	std::cout << "Please input mRNA codons:";
	std::cin >> mrna;
	Translator translator;
	translator.loadmRNA(mrna);
	return translator;
}

int main(int argc, char* argv[]){
	std::cout << menu;
	int choice;
	Tranlator translator;
	std::cin >> choice;
	switch(choice) {
		case 1:
			translator = inputFile();
			break;
		case 2:
			translator = STDIN();
			break;
		case 3:
		default:
			return 0;
			break;
	}
	Translator translator 

	std::cout << "Please Enter Output filename: \n";
	
	std::string outputFilename;
	std::cin >> outputFilename;

	translator.saveToFile(outputFilename);
	return 0;
}

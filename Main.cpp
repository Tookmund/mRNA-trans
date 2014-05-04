#include <iostream>
#include "Translator.h"

std::string start = 
"+---------------------+\n"
"|   mRNA Translator   |\n"
"|=====================|\n"
"| [1] Read from File  |\n"
"| [2] Read from STDIN |\n"
"| [3] Quit            |\n"
"+---------------------+\n";

std::string ending = 
"+----------------------+\n"
"| [1] Output to File   |\n"
"| [2] Output to STDOUT |\n"
"+----------------------+\n";

Translator inputFile () {
	std::cout << "Please Enter input filename: \n";
	
	std::string filename;
	std::cin >> filename;

	Translator translator;

	if(translator.loadmRNAFromFile(filename) != 0) {
		translator.loadmRNA("  ");
	}
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
	std::cout << start;
	int choice1;
	Translator translator;
	std::cin >> choice1;
	switch(choice1) {
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

	std::cout << ending;
	int choice2
	std::cin >> choice2;
	switch(choice2) {
		case 1: //Output to File
			std::string fileout;
			std::cout << "Please Enter Output Filename: \n";
			std::cin >> fileout;
			translator.saveToFile(fileout);
			break;
		case 2: //Output to STDOUT
			translator.printAminoStrand();
			break;
		default:
			break;
	}
	return 0;
}

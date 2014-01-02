#include <iostream>
#include "Translator.h"

int main(int argc, char* argv[]){

	std::cout << "loading File...\n";

	Translator translator;

	translator.loadmRNAFromFile("FILE");
	translator.translate();
	translator.printmRNA();

	std::cout << "Partitioning.." << std::endl;
	translator.printCodonStrand();
    std::cout << "translating.." << std::endl;
    translator.printAminoStrand();

	return 0;
}

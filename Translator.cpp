#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Translator.h"

void Translator::trimmRNA()
{
	//Makes everythinglowercase
	std::transform(mRNA.begin(), mRNA.end(), mRNA.begin(), ::tolower);
	//Removing anything that isnt an RNA base (A, U ,G, C)
	for(int i = 0; i < mRNA.length(); i++){
		switch (mRNA.at(i)){
			case 'a':
				break;
			case 'u':
				break;
			case 'g':
				break;
			case 'c':
				break;
			default:
				mRNA[i] = ' ';
		}
	}
	mRNA.erase(remove(mRNA.begin(), mRNA.end(), ' '), mRNA.end());
}

void Translator::partitionRNA()
{
	if(mRNA.size()%3 != 0){
		std::cout << "Warning, not enough codons to use up RNA bases," << 
							"rna bases not evenly divided by 3" << std::endl;
	}

	for(int i = 0; i< mRNA.size(); i+= 3)
	{
		codonStrand.push_back(mRNA.substr(i,3));
	}

}


void Translator::loadmRNA(std::string str)
{
	mRNA = str;
}

void Translator::loadmRNAFromFile(std::string filename)
{
	std::fstream file;
	file.open(filename.c_str());

	if(file.is_open()){
		std::stringstream stream;
		stream << file.rdbuf();
		mRNA = stream.str();
		file.close();
	}
	else{
		std::cout << "Requested mRNA file does not exist" << std::endl;
	}
}


void Translator::printmRNA()
{
	std::cout << mRNA << std::endl;
}

void Translator::printCodonStrand()
{
	for(int i = 0; i < codonStrand.size(); i++)
	{
		std::cout << codonStrand.at(i) << std::endl;
	}
}

void Translator::printAminoStrand()
{
	for(int i = 0; i < aminoStrand.size(); i++){
		std::cout << aminoStrand.at(i) << std::endl;
	}	
}

void Translator::translate()
{
	trimmRNA();
	partitionRNA();

	for(int i = 0; i < codonStrand.size(); i++)
	{

		if(codonStrand.at(i).compare("uuu") == 0)
			aminoStrand.push_back("phe");
		else if(codonStrand.at(i).compare("uuc") == 0)
			aminoStrand.push_back("phe");
		else if(codonStrand.at(i).compare("uua") == 0)
			aminoStrand.push_back("leu");
		else if(codonStrand.at(i).compare("uug") == 0)
			aminoStrand.push_back("leu");
		else if(codonStrand.at(i).compare("ucu") == 0)
			aminoStrand.push_back("ser");
		else if(codonStrand.at(i).compare("ucc") == 0)
			aminoStrand.push_back("ser");
		else if(codonStrand.at(i).compare("uca") == 0)
			aminoStrand.push_back("ser");
		else if(codonStrand.at(i).compare("ucg") == 0)
			aminoStrand.push_back("ser");
		else if(codonStrand.at(i).compare("uau") == 0)
			aminoStrand.push_back("tyr");
		else if(codonStrand.at(i).compare("uac") == 0)
			aminoStrand.push_back("tyr");
		else if(codonStrand.at(i).compare("uaa") == 0)
			aminoStrand.push_back("stop");
		else if(codonStrand.at(i).compare("uag") == 0)
			aminoStrand.push_back("stop");
		else if(codonStrand.at(i).compare("ugu") == 0)
			aminoStrand.push_back("cys");
		else if(codonStrand.at(i).compare("ugc") == 0)
			aminoStrand.push_back("cys");
		else if(codonStrand.at(i).compare("uga") == 0)
			aminoStrand.push_back("stop");
		else if(codonStrand.at(i).compare("ugg") == 0)
			aminoStrand.push_back("trp");
		else if(codonStrand.at(i).compare("cuu") == 0)
			aminoStrand.push_back("leu");
		else if(codonStrand.at(i).compare("cuc") == 0)
			aminoStrand.push_back("leu");
		else if(codonStrand.at(i).compare("cua") == 0)
			aminoStrand.push_back("leu");
		else if(codonStrand.at(i).compare("cug") == 0)
			aminoStrand.push_back("leu");
		else if(codonStrand.at(i).compare("ccu") == 0)
			aminoStrand.push_back("pro");
		else if(codonStrand.at(i).compare("ccc") == 0)
			aminoStrand.push_back("pro");
		else if(codonStrand.at(i).compare("cca") == 0)
			aminoStrand.push_back("pro");
		else if(codonStrand.at(i).compare("ccg") == 0)
			aminoStrand.push_back("pro");
		else if(codonStrand.at(i).compare("cau") == 0)
			aminoStrand.push_back("his");
		else if(codonStrand.at(i).compare("cac") == 0)
			aminoStrand.push_back("his");
		else if(codonStrand.at(i).compare("caa") == 0)
			aminoStrand.push_back("gln");
		else if(codonStrand.at(i).compare("cag") == 0)
			aminoStrand.push_back("gln");
		else if(codonStrand.at(i).compare("cgu") == 0)
			aminoStrand.push_back("arg");
		else if(codonStrand.at(i).compare("cgc") == 0)
			aminoStrand.push_back("arg");
		else if(codonStrand.at(i).compare("cga") == 0)
			aminoStrand.push_back("arg");
		else if(codonStrand.at(i).compare("cgg") == 0)
			aminoStrand.push_back("arg");
		else if(codonStrand.at(i).compare("auu") == 0)
			aminoStrand.push_back("ile");
		else if(codonStrand.at(i).compare("auc") == 0)
			aminoStrand.push_back("ile");
		else if(codonStrand.at(i).compare("aua") == 0)
			aminoStrand.push_back("ile");
		else if(codonStrand.at(i).compare("aug") == 0)
			aminoStrand.push_back("met");
		else if(codonStrand.at(i).compare("acu") == 0)
			aminoStrand.push_back("thr");
		else if(codonStrand.at(i).compare("acc") == 0)
			aminoStrand.push_back("thr");
		else if(codonStrand.at(i).compare("aca") == 0)
			aminoStrand.push_back("thr");
		else if(codonStrand.at(i).compare("acg") == 0)
			aminoStrand.push_back("thr");
		else if(codonStrand.at(i).compare("aau") == 0)
			aminoStrand.push_back("asn");
		else if(codonStrand.at(i).compare("aac") == 0)
			aminoStrand.push_back("asn");
		else if(codonStrand.at(i).compare("aaa") == 0)
			aminoStrand.push_back("lys");
		else if(codonStrand.at(i).compare("aag") == 0)
			aminoStrand.push_back("lys");
		else if(codonStrand.at(i).compare("agu") == 0)
			aminoStrand.push_back("ser");
		else if(codonStrand.at(i).compare("agc") == 0)
			aminoStrand.push_back("ser");
		else if(codonStrand.at(i).compare("aga") == 0)
			aminoStrand.push_back("arg");
		else if(codonStrand.at(i).compare("agg") == 0)
			aminoStrand.push_back("arg");
		else if(codonStrand.at(i).compare("guu") == 0)
			aminoStrand.push_back("val");
		else if(codonStrand.at(i).compare("guc") == 0)
			aminoStrand.push_back("val");
		else if(codonStrand.at(i).compare("gua") == 0)
			aminoStrand.push_back("val");
		else if(codonStrand.at(i).compare("gug") == 0)
			aminoStrand.push_back("val");
		else if(codonStrand.at(i).compare("gcu") == 0)
			aminoStrand.push_back("ala");
		else if(codonStrand.at(i).compare("gcc") == 0)
			aminoStrand.push_back("ala");
		else if(codonStrand.at(i).compare("gca") == 0)
			aminoStrand.push_back("ala");
		else if(codonStrand.at(i).compare("gcg") == 0)
			aminoStrand.push_back("ala");
		else if(codonStrand.at(i).compare("gau") == 0)
			aminoStrand.push_back("asp");
		else if(codonStrand.at(i).compare("gac") == 0)
			aminoStrand.push_back("asp");
		else if(codonStrand.at(i).compare("gaa") == 0)
			aminoStrand.push_back("glu");
		else if(codonStrand.at(i).compare("gag") == 0)
			aminoStrand.push_back("glu");
		else if(codonStrand.at(i).compare("ggu") == 0)
			aminoStrand.push_back("gly");
		else if(codonStrand.at(i).compare("ggc") == 0)
			aminoStrand.push_back("gly");
		else if(codonStrand.at(i).compare("gga") == 0)
			aminoStrand.push_back("gly");
		else if(codonStrand.at(i).compare("ggg") == 0)
			aminoStrand.push_back("gly");
		else
			aminoStrand.push_back("none/error");


	}
}
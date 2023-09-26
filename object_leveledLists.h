#ifndef LEVELED_LIST_H
#define LEVELED_LIST_H

using namespace std;

#include "PCH.h"
#include "dirent.h"
#include "gameforms.h"
#include "utility.h"
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

namespace LEVELEDLISTS
{

	struct struct_ll
	{
		uint32_t size;
		RE::LEVELED_OBJECT ll[];
	};

	struct line_content
	{


		std::string object;
		std::string level;
		std::string reference;
		std::string count;
		std::string chance;
		std::string clear;
		std::string calcForLevel;
		std::string calcEachItem;
		std::string calcForLevelAndEachItem;
		std::string calcUseAll;
		
		std::vector<std::string> objects;
		std::vector<std::string> containerObjects;
		std::vector<std::vector<std::string>> addedObjects;
		std::vector<std::vector<std::string>> addedContainerObjects;
		std::vector<std::string> removedContainerObjects;
		std::vector<std::vector<std::string>> removedObjects;
		std::vector<std::vector<std::string>> templateKeyword;
		std::vector<std::string> removeItemsByKeyword;
		std::string noFilterLL;
	};

	struct line_content create_patch_instruction(const std::string& line);
	void process_patch_instructions(const std::list<line_content>& tokens);
	void* readConfig(const std::string& folder);
	void process_patch_instructions(const std::list<line_content>& tokens);
	void patch(LEVELEDLISTS::line_content line, RE::TESLevItem* curobj);
	void patchContainer(LEVELEDLISTS::line_content line, RE::TESObjectCONT* curobj);
}

#endif

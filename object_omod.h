#ifndef OMOD_H
#define OMOD_H

using namespace std;

#	include "PCH.h"
#	include "dirent.h"
#	include "gameforms.h"
#	include "utility.h"
#	include <fstream>
#	include <iostream>
#	include <regex>
#	include <string>
#	include <vector>

namespace OMOD
{
	struct line_content
	{
		std::vector<std::string> objects;

		
		std::vector<std::string> FormAnd;
		std::vector<std::string> PropertyAnd;
		std::vector<std::string> PropertyOr;
		std::vector<std::string> PropertyExclude;
		

		std::vector<std::string> stringContainsAnd;
		std::vector<std::string> stringContainsOr;
		std::vector<std::string> stringContainsExclude;
		std::string regexSearchString;
		std::string value1;
		std::string value2;
		std::vector<std::string> properties;
		std::vector<std::string> propertiesValues;
		std::vector<std::string> functionTypeProperties;
		std::vector<std::string> functionTypeValues;
		
		std::vector<std::string> propertiesVP;
		std::vector<std::string> propertiesVPValues;
		std::vector<std::string> propertiesForm;
		std::vector<std::string> propertiesFormValues;
		std::vector<std::string> propertiesToRemove;
		std::vector<std::string> propertiesToRemoveValues;
		std::vector<std::string> propertiesToRemoveForm;
		std::vector<std::string> propertiesToRemovePV;
		std::vector<std::string> propertiesToAdd;
		std::vector<std::string> attachParentSlotKeywordsToAdd;
		std::vector<std::string> attachParentSlotKeywordsToRemove;
		std::string attachPoint;
		std::string targetType;
		std::string fullName;
		std::string description;
		std::string connectionAnd;
		std::string functionType;
		std::vector<std::string> keywordsToAdd;
		std::vector<std::string> keywordsToRemove;
		std::vector<std::string> attachPointKeywordsFilter;
	};

	struct line_content create_patch_instruction(const std::string& line);
	void process_patch_instructions(const std::list<line_content>& tokens);
	void* readConfig(const std::string& folder);
	void* patch(OMOD::line_content line, RE::BGSMod::Attachment::Mod* curobj);
}

#endif

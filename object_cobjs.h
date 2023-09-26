#ifndef COBJ_H
#define COBJ_H

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

namespace COBJ
{
	struct line_content
	{
		std::vector<std::string> objects;
		std::vector<std::string> filterWorkbenchKeyword;
		std::vector<std::string> filterCategoryKeyword;
		std::string workbenchKeyword;
		std::vector<std::string> categoryKeywordToAdd;
		std::vector<std::string> categoryKeywordToRemove;


	};

	struct line_content create_patch_instruction(const std::string& line);
	void process_patch_instructions(const std::list<line_content>& tokens);
	void* readConfig(const std::string& folder);
	void* patch(COBJ::line_content line, RE::BGSConstructibleObject* curobj);
}

#endif

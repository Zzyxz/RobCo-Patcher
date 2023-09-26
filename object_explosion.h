#ifndef MISC_H
#define MISC_H

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

namespace MISC
{
	struct line_content
	{
		std::vector<std::string> objects;

	};

	struct line_content create_patch_instruction(const std::string& line);
	void process_patch_instructions(const std::list<line_content>& tokens);
	void* readConfig(const std::string& folder);
	void* patch(MISC::line_content line, RE::TESObjectMISC* curobj);
}

#endif

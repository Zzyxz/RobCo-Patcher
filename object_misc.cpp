#include "object_misc.h"
namespace MISC
{

struct line_content create_patch_instruction(const std::string& line)
{
	line_content l;

	// extract objects
	std::regex objects_regex("filterByMiscs\\s*=([^:]+)", regex::icase);
	std::smatch objects_match;
	std::regex_search(line, objects_match, objects_regex);
	std::vector<std::string> objects;
	if (objects_match.empty() || objects_match[1].str().empty()) {
		//empty
	} else {
		std::string objects_str = objects_match[1];
		std::regex objects_list_regex("[a-zA-Z0-9_\\-. ]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
		std::sregex_iterator objects_iterator(objects_str.begin(), objects_str.end(), objects_list_regex);
		std::sregex_iterator objects_end;
		while (objects_iterator != objects_end) {
			std::string tempVar = (*objects_iterator)[0].str();
			tempVar.erase(tempVar.begin(), std::find_if_not(tempVar.begin(), tempVar.end(), ::isspace));
			tempVar.erase(std::find_if_not(tempVar.rbegin(), tempVar.rend(), ::isspace).base(), tempVar.end());
			//logger::info(FMT_STRING("Race: {}"), race);
			if (tempVar != "none") {
				objects.push_back(tempVar);
			}
			++objects_iterator;
		}
		l.objects = objects;
	}

	// extract filterByHasComponent
	std::regex filterByHasComponent_regex("filterByHasComponent\\s*=([^:]+)", regex::icase);
	std::smatch filterByHasComponentmatch;
	std::regex_search(line, filterByHasComponentmatch, filterByHasComponent_regex);
	// extract the value after the equals sign
	if (filterByHasComponentmatch.empty() || filterByHasComponentmatch[1].str().empty()) {
		l.filterByHasComponent = "none";
	} else {
		std::string value = filterByHasComponentmatch[1].str();
		value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
		l.filterByHasComponent = value;
	}

		// extract filterByHasComponentExclude
	std::regex filterByHasComponentExclude_regex("filterByHasNoComponent\\s*=([^:]+)", regex::icase);
	std::smatch filterByHasComponentExcludematch;
	std::regex_search(line, filterByHasComponentExcludematch, filterByHasComponentExclude_regex);
	// extract the value after the equals sign
	if (filterByHasComponentExcludematch.empty() || filterByHasComponentExcludematch[1].str().empty()) {
		l.filterByHasNoComponent = "none";
	} else {
		std::string value = filterByHasComponentExcludematch[1].str();
		value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
		l.filterByHasNoComponent = value;
	}

	// extract keywords
	std::regex keywords_regex("filterByKeywords\\s*=([^:]+)", regex::icase);
	std::smatch keywords_match;
	std::regex_search(line, keywords_match, keywords_regex);
	std::vector<std::string> keywords;
	if (keywords_match.empty() || keywords_match[1].str().empty()) {
		//empty
	} else {
		std::string keywords_str = keywords_match[1];
		std::regex keywords_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
		std::sregex_iterator keywords_iterator(keywords_str.begin(), keywords_str.end(), keywords_list_regex);
		std::sregex_iterator keywords_end;
		while (keywords_iterator != keywords_end) {
			std::string keyword = (*keywords_iterator)[0].str();
			keyword.erase(keyword.begin(), std::find_if_not(keyword.begin(), keyword.end(), ::isspace));
			keyword.erase(std::find_if_not(keyword.rbegin(), keyword.rend(), ::isspace).base(), keyword.end());
			if (keyword != "none") {
				keywords.push_back(keyword);
			}
			++keywords_iterator;
		}
		l.keywords = keywords;
	}

	// extract keywords
	std::regex keywordsOr_regex("filterByKeywordsOr\\s*=([^:]+)", regex::icase);
	std::smatch keywordsOr_match;
	std::regex_search(line, keywordsOr_match, keywordsOr_regex);
	std::vector<std::string> keywordsOr;
	if (keywordsOr_match.empty() || keywordsOr_match[1].str().empty()) {
		//empty
	} else {
		std::string keywordsOr_str = keywordsOr_match[1];
		std::regex keywordsOr_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
		std::sregex_iterator keywordsOr_iterator(keywordsOr_str.begin(), keywordsOr_str.end(), keywordsOr_list_regex);
		std::sregex_iterator keywordsOr_end;
		while (keywordsOr_iterator != keywordsOr_end) {
			std::string keyword = (*keywordsOr_iterator)[0].str();
			keyword.erase(keyword.begin(), std::find_if_not(keyword.begin(), keyword.end(), ::isspace));
			keyword.erase(std::find_if_not(keyword.rbegin(), keyword.rend(), ::isspace).base(), keyword.end());
			if (keyword != "none") {
				keywordsOr.push_back(keyword);
			}
			++keywordsOr_iterator;
		}
		l.keywordsOr = keywordsOr;
	}

	// extract keywords
	std::regex keywordsExcluded_regex("filterByKeywordsExcluded\\s*=([^:]+)", regex::icase);
	std::smatch keywordsExcluded_match;
	std::regex_search(line, keywordsExcluded_match, keywordsExcluded_regex);
	std::vector<std::string> keywordsExcluded;
	if (keywordsExcluded_match.empty() || keywordsExcluded_match[1].str().empty()) {
		//empty
	} else {
		std::string keywordsExcluded_str = keywordsExcluded_match[1];
		std::regex keywordsExcluded_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
		std::sregex_iterator keywordsExcluded_iterator(keywordsExcluded_str.begin(), keywordsExcluded_str.end(), keywordsExcluded_list_regex);
		std::sregex_iterator keywordsExcluded_end;
		while (keywordsExcluded_iterator != keywordsExcluded_end) {
			std::string keyword = (*keywordsExcluded_iterator)[0].str();
			keyword.erase(keyword.begin(), std::find_if_not(keyword.begin(), keyword.end(), ::isspace));
			keyword.erase(std::find_if_not(keyword.rbegin(), keyword.rend(), ::isspace).base(), keyword.end());
			if (keyword != "none") {
				keywordsExcluded.push_back(keyword);
			}
			++keywordsExcluded_iterator;
		}
		l.keywordsExcluded = keywordsExcluded;
	}

					// extract weight
	std::regex weight_regex("weight\\s*=([^:]+)", regex::icase);
	std::smatch weightmatch;
	std::regex_search(line, weightmatch, weight_regex);
	// extract the value after the equals sign
	if (weightmatch.empty() || weightmatch[1].str().empty()) {
		l.weight = "none";
	} else {
		std::string value = weightmatch[1].str();
		value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
		l.weight = value;
	}

		// extract weightMultiply
	std::regex weightMultiply_regex("weightMultiply\\s*=([^:]+)", regex::icase);
	std::smatch weightMultiplymatch;
	std::regex_search(line, weightMultiplymatch, weightMultiply_regex);
	// extract the value after the equals sign
	if (weightMultiplymatch.empty() || weightMultiplymatch[1].str().empty()) {
		l.weightMultiply = "none";
	} else {
		std::string value = weightMultiplymatch[1].str();
		value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
		l.weightMultiply = value;
	}

	// extract capsvalue
	std::regex capsvalue_regex("value\\s*=([^:]+)", regex::icase);
	std::smatch capsvaluematch;
	std::regex_search(line, capsvaluematch, capsvalue_regex);
	// extract the value after the equals sign
	if (capsvaluematch.empty() || capsvaluematch[1].str().empty()) {
		l.capsvalue = "none";
	} else {
		std::string value = capsvaluematch[1].str();
		value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
		l.capsvalue = value;
	}



	return l;
}

void process_patch_instructions(const std::list<line_content>& tokens)
{
	logger::debug("processing patch instructions");
	const auto dataHandler = RE::TESDataHandler::GetSingleton();
	RE::BSTArray<RE::TESObjectMISC*> objectArray = dataHandler->GetFormArray<RE::TESObjectMISC>();
	for (const auto& line : tokens) {

		if (!line.objects.empty()) {
			//logger::info("npc not empty");
			for (const auto& objectstring : line.objects) {
				RE::TESForm* currentform = nullptr;
				RE::TESObjectMISC* object = nullptr;

				std::string string_form = objectstring;
				currentform = GetFormFromIdentifier(string_form);
				if (currentform && currentform->formType == RE::ENUM_FORM_ID::kAMMO) {
					object = (RE::TESObjectMISC*)currentform;
					patch(line, object);

				}
			}
		}

		if (!line.objects.empty() && line.filterByHasComponent.empty() && line.filterByHasNoComponent.empty() && line.keywords.empty() && line.keywordsOr.empty()) {
			continue;
		}

		for (const auto& curobj : objectArray) {

			bool found = false;
			bool keywordAnd = false;
			bool keywordOr = false;

			if (!line.filterByHasComponent.empty() && line.filterByHasComponent != "none") {
				if (curobj->componentData && curobj->componentData[0].size() > 0) {
					//logger::debug(FMT_STRING("misc formid: {:08X} {} has component data "), curobj->formID, curobj->fullName);
					found = true;
				}
			}

			if (!line.filterByHasNoComponent.empty() && line.filterByHasNoComponent != "none") {
				if (!curobj->componentData) {
					//logger::debug(FMT_STRING("misc formid: {:08X} {} has no component data "), curobj->formID, curobj->fullName);
					found = true;
				}
			}

			if (!line.keywords.empty()) {
				//logger::info("keywords not empty");
				for (const auto& keywordstring : line.keywords) {
					RE::TESForm* currentform = nullptr;
					RE::BGSKeyword* keyword = nullptr;

					std::string string_form = keywordstring;
					currentform = GetFormFromIdentifier(string_form);
					if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
						keyword = (RE::BGSKeyword*)currentform;

						if (curobj->HasKeyword(keyword)) {
							keywordAnd = true;
						} else {
							keywordAnd = false;
							//logger::debug(FMT_STRING("KeywordAnd Weapon does not have all keywords"));
							break;
						}
						//logger::debug(FMT_STRING("KeywordAnd Weapon true"));
					}
				}
			} else {
				//logger::debug(FMT_STRING("KeywordAnd is empty, we pass true."));
				keywordAnd = true;
			}
			if (!line.keywordsOr.empty()) {
				//logger::info("keywords not empty");
				for (const auto& keywordstring : line.keywordsOr) {
					RE::TESForm* currentform = nullptr;
					RE::BGSKeyword* keyword = nullptr;

					std::string string_form = keywordstring;
					currentform = GetFormFromIdentifier(string_form);
					if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
						keyword = (RE::BGSKeyword*)currentform;

						if (curobj->HasKeyword(keyword)) {
							keywordOr = true;
							//logger::debug(FMT_STRING("KeywordOr has at least one keyword true {:08X} {}"), curobj->formID, curobj->fullName);
							//logger::info("Keyword found.");
							break;
						}
					}
				}
			} else {
				//logger::debug(FMT_STRING("KeywordOr is empty, we pass true."));
				keywordOr = true;
			}

			if ((!line.keywords.empty() || !line.keywordsOr.empty()) && keywordAnd && keywordOr) {
				//logger::debug(FMT_STRING("Found a matching weapon by keywords. {:08X} {}"), curobj->formID, curobj->fullName);
				found = true;
			}



			if (!found && line.objects.empty() && line.filterByHasComponent.empty() && line.filterByHasNoComponent.empty() && line.keywords.empty() && line.keywordsOr.empty()) {
				found = true;
			}



			if (!line.keywordsExcluded.empty()) {
				//logger::info("keywords not empty");
				for (const auto& keywordstring : line.keywordsExcluded) {
					RE::TESForm* currentform = nullptr;
					RE::BGSKeyword* keyword = nullptr;

					std::string string_form = keywordstring;
					currentform = GetFormFromIdentifier(string_form);
					if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
						keyword = (RE::BGSKeyword*)currentform;

						if (curobj->HasKeyword(keyword)) {
							found = false;
							//logger::debug(FMT_STRING("KeywordExcluded has a keyword that is excluded.{:08X}"),keyword->formID);
							//logger::info("Keyword found.");
							break;
						}
					}
				}
			}


			if (found) {
				patch(line, curobj);
			}

		}
	}
}

void* readConfig(const std::string& folder)
	{
		char skipChar = '/';
		std::string extension = ".ini";

		DIR* dir;
		struct dirent* ent;
		std::list<std::string> directories{ folder };
		std::string currentFolder;

		while (!directories.empty()) {
			currentFolder = directories.front();
			directories.pop_front();
			if ((dir = opendir(currentFolder.c_str())) != NULL) {
				while ((ent = readdir(dir)) != NULL) {
					if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
						std::string fullPath = currentFolder + "\\" + ent->d_name;
						struct _stat st;
						if (_stat(fullPath.c_str(), &st) == 0 && (_S_IFDIR & st.st_mode)) {
							directories.push_back(fullPath);
						} else {
							std::string fileName = ent->d_name;
							size_t pos = fileName.find(extension);
							if (pos != std::string::npos) {
								fileName = fileName.substr(0, pos);
								const char* modname = fileName.c_str();

								if ((strstr(modname, ".esp") != nullptr || strstr(modname, ".esl") != nullptr || strstr(modname, ".esm") != nullptr)) {
									if (!IsPluginInstalled(modname)) {
										logger::info("************************************************************");
										logger::info(FMT_STRING("{} not found or is not a valid plugin file, skipping config file {}."), modname, fullPath);
										logger::info("************************************************************");
										continue;
									}
								}
								logger::info("************************************************************");
								logger::info(FMT_STRING("Processing config file {}... "), fullPath.c_str());
								logger::info("************************************************************");
								std::string line;
								std::ifstream infile;
								std::list<line_content> tokens;
								infile.open(fullPath);
								while (std::getline(infile, line)) {
									if (line[0] == skipChar) {
										continue;
									}

									if (line.empty()) {
										continue;
									}

									tokens.push_back(create_patch_instruction(line));
								}
								infile.close();
								process_patch_instructions(tokens);
							}
						}
					}
				}
				closedir(dir);
			} else {
				logger::info(FMT_STRING("Couldn't open directory {}."), currentFolder.c_str());
			}
		}
	}

	void* patch(MISC::line_content line, RE::TESObjectMISC* curobj)
	{
		if (!line.weight.empty() && line.weight != "none") {
			try {
				curobj->weight = std::stof(line.weight);
				logger::debug(FMT_STRING("misc formid: {:08X} {} changed weight {}"), curobj->formID, curobj->fullName, curobj->weight);
			} catch (const std::invalid_argument& e) {
			}
		}

		if (!line.weightMultiply.empty() && line.weightMultiply != "none") {
			try {
				curobj->weight = curobj->weight * std::stof(line.weightMultiply);
				logger::debug(FMT_STRING("misc formid: {:08X} {} changed weight by multiplier {}"), curobj->formID, curobj->fullName, curobj->weight);
			} catch (const std::invalid_argument& e) {
			}
		}

		if (!line.capsvalue.empty() && line.capsvalue != "none") {
			try {
				curobj->value = std::stof(line.capsvalue);
				logger::debug(FMT_STRING("misc formid: {:08X} {} changed value {}"), curobj->formID, curobj->fullName, curobj->value);
			} catch (const std::invalid_argument& e) {
			}
		}

		

	}

}

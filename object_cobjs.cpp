#include "object_cobjs.h"
namespace COBJ
{

	struct line_content create_patch_instruction(const std::string& line)
	{
		line_content l;

		// extract objects
		std::regex objects_regex("filterByCobjs\\s*=([^:]+)", regex::icase);
		std::smatch objects_match;
		std::regex_search(line, objects_match, objects_regex);
		std::vector<std::string> objects;
		if (objects_match.empty() || objects_match[1].str().empty()) {
			//empty
		} else {
			std::string objects_str = objects_match[1];
			std::regex objects_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
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

		// extract workBenchKeyword
		std::regex workBenchKeyword_regex("filterByWorkbenchKeywordsOr\\s*=([^:]+)", regex::icase);
		std::smatch workBenchKeyword_match;
		std::regex_search(line, workBenchKeyword_match, workBenchKeyword_regex);
		std::vector<std::string> workBenchKeyword;
		if (workBenchKeyword_match.empty() || workBenchKeyword_match[1].str().empty()) {
			//empty
		} else {
			std::string workBenchKeyword_str = workBenchKeyword_match[1];
			std::regex workBenchKeyword_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator workBenchKeyword_iterator(workBenchKeyword_str.begin(), workBenchKeyword_str.end(), workBenchKeyword_list_regex);
			std::sregex_iterator workBenchKeyword_end;
			while (workBenchKeyword_iterator != workBenchKeyword_end) {
				std::string tempVar = (*workBenchKeyword_iterator)[0].str();
				tempVar.erase(tempVar.begin(), std::find_if_not(tempVar.begin(), tempVar.end(), ::isspace));
				tempVar.erase(std::find_if_not(tempVar.rbegin(), tempVar.rend(), ::isspace).base(), tempVar.end());
				//logger::info(FMT_STRING("Race: {}"), race);
				if (tempVar != "none") {
					workBenchKeyword.push_back(tempVar);
				}
				++workBenchKeyword_iterator;
			}
			l.filterWorkbenchKeyword = workBenchKeyword;
		}

		// extract categoryKeyword
		std::regex categoryKeyword_regex("filterByCategoryKeywordsOr\\s*=([^:]+)", regex::icase);
		std::smatch categoryKeyword_match;
		std::regex_search(line, categoryKeyword_match, categoryKeyword_regex);
		std::vector<std::string> categoryKeyword;
		if (categoryKeyword_match.empty() || categoryKeyword_match[1].str().empty()) {
			//empty
		} else {
			std::string categoryKeyword_str = categoryKeyword_match[1];
			std::regex categoryKeyword_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator categoryKeyword_iterator(categoryKeyword_str.begin(), categoryKeyword_str.end(), categoryKeyword_list_regex);
			std::sregex_iterator categoryKeyword_end;
			while (categoryKeyword_iterator != categoryKeyword_end) {
				std::string tempVar = (*categoryKeyword_iterator)[0].str();
				tempVar.erase(tempVar.begin(), std::find_if_not(tempVar.begin(), tempVar.end(), ::isspace));
				tempVar.erase(std::find_if_not(tempVar.rbegin(), tempVar.rend(), ::isspace).base(), tempVar.end());
				//logger::info(FMT_STRING("Race: {}"), race);
				if (tempVar != "none") {
					categoryKeyword.push_back(tempVar);
				}
				++categoryKeyword_iterator;
			}
			l.filterCategoryKeyword = categoryKeyword;
		}

		// extract keywordsToAdd
		std::regex keywordsToAdd_regex("categoryKeywordsToAdd\\s*=([^:]+)", regex::icase);
		std::smatch keywordsToAdd_match;
		std::regex_search(line, keywordsToAdd_match, keywordsToAdd_regex);
		std::vector<std::string> keywordsToAdd;
		if (keywordsToAdd_match.empty() || keywordsToAdd_match[1].str().empty()) {
			//empty
		} else {
			std::string keywordsToAdd_str = keywordsToAdd_match[1];
			std::regex keywordsToAdd_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator keywordsToAdd_iterator(keywordsToAdd_str.begin(), keywordsToAdd_str.end(), keywordsToAdd_list_regex);
			std::sregex_iterator keywordsToAdd_end;
			while (keywordsToAdd_iterator != keywordsToAdd_end) {
				std::string keywordToAdd = (*keywordsToAdd_iterator)[0].str();
				keywordToAdd.erase(keywordToAdd.begin(), std::find_if_not(keywordToAdd.begin(), keywordToAdd.end(), ::isspace));
				keywordToAdd.erase(std::find_if_not(keywordToAdd.rbegin(), keywordToAdd.rend(), ::isspace).base(), keywordToAdd.end());
				if (keywordToAdd != "none") {
					//logger::info(FMT_STRING("keywordsToAdd: {}"), keywordToAdd);
					keywordsToAdd.push_back(keywordToAdd);
				}
				++keywordsToAdd_iterator;
			}
			l.categoryKeywordToAdd = keywordsToAdd;
		}

		// extract keywordsToRemove
		std::regex keywordsToRemove_regex("categoryKeywordsToRemove\\s*=([^:]+)", regex::icase);
		std::smatch keywordsToRemove_match;
		std::regex_search(line, keywordsToRemove_match, keywordsToRemove_regex);
		std::vector<std::string> keywordsToRemove;
		if (keywordsToRemove_match.empty() || keywordsToRemove_match[1].str().empty()) {
			//empty
		} else {
			std::string keywordsToRemove_str = keywordsToRemove_match[1];
			std::regex keywordsToRemove_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator keywordsToRemove_iterator(keywordsToRemove_str.begin(), keywordsToRemove_str.end(), keywordsToRemove_list_regex);
			std::sregex_iterator keywordsToRemove_end;
			while (keywordsToRemove_iterator != keywordsToRemove_end) {
				std::string keywordToRemove = (*keywordsToRemove_iterator)[0].str();
				keywordToRemove.erase(keywordToRemove.begin(), std::find_if_not(keywordToRemove.begin(), keywordToRemove.end(), ::isspace));
				keywordToRemove.erase(std::find_if_not(keywordToRemove.rbegin(), keywordToRemove.rend(), ::isspace).base(), keywordToRemove.end());
				if (keywordToRemove != "none") {
					//logger::info(FMT_STRING("keywordsToRemove: {}"), keywordToRemove);
					keywordsToRemove.push_back(keywordToRemove);
				}
				++keywordsToRemove_iterator;
			}
			l.categoryKeywordToRemove = keywordsToRemove;
		}

		// extract workbenchKeyword
		std::regex workbenchKeyword_regex("workbenchKeyword\\s*=([^:]+)", regex::icase);
		std::smatch benchmatch;
		std::regex_search(line, benchmatch, workbenchKeyword_regex);
		// extract the value after the equals sign
		if (benchmatch.empty() || benchmatch[1].str().empty()) {
			l.workbenchKeyword = "none";
		} else {
			std::string keyword = benchmatch[1].str();
			keyword.erase(std::remove_if(keyword.begin(), keyword.end(), ::isspace), keyword.end());
			l.workbenchKeyword = keyword;
		}

		return l;
	}

	void process_patch_instructions(const std::list<line_content>& tokens)
	{
		logger::debug("processing patch instructions");
		const auto dataHandler = RE::TESDataHandler::GetSingleton();
		RE::BSTArray<RE::BGSConstructibleObject*> objectArray = dataHandler->GetFormArray<RE::BGSConstructibleObject>();
		for (const auto& line : tokens) {
			if (!line.objects.empty()) {
				for (const auto& objectstring : line.objects) {
					RE::TESForm* currentform = nullptr;
					RE::BGSConstructibleObject* object = nullptr;

					std::string string_form = objectstring;
					currentform = GetFormFromIdentifier(string_form);
					if (currentform && currentform->formType == RE::ENUM_FORM_ID::kCOBJ) {
						object = (RE::BGSConstructibleObject*)currentform;
						patch(line, object);
					}
				}
			}

			if (!line.objects.empty() && line.filterWorkbenchKeyword.empty() && line.filterCategoryKeyword.empty()) {
				continue;
			}

			for (const auto& curobj : objectArray) {
				bool found = false;

				if (!line.filterWorkbenchKeyword.empty()) {
					//logger::info("keywords not empty");
					for (const auto& keywordstring : line.filterWorkbenchKeyword) {
						RE::TESForm* currentform = nullptr;
						RE::BGSKeyword* keyword = nullptr;

						std::string string_form = keywordstring;
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
							keyword = (RE::BGSKeyword*)currentform;

							if (curobj->benchKeyword->formID == keyword->formID) {
								found = true;
								//logger::debug(FMT_STRING("KeywordOr has at least one keyword true {:08X} {}"), curobj->formID, curobj->fullName);
								//logger::info("Keyword found.");
								break;
							}
						}
					}
				}

				if (!line.filterCategoryKeyword.empty()) {
					//logger::info("keywords not empty");
					for (const auto& keywordstring : line.filterCategoryKeyword) {
						RE::TESForm* currentform = nullptr;
						RE::BGSKeyword* keyword = nullptr;

						std::string string_form = keywordstring;
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
							keyword = (RE::BGSKeyword*)currentform;

							if (curobj->filterKeywords.HasKeyword(keyword)) {
								found = true;
								//logger::debug(FMT_STRING("KeywordOr has at least one keyword true {:08X} {}"), curobj->formID, curobj->fullName);
								//logger::info("Keyword found.");
								break;
							}
						}
					}
				}

				if (line.objects.empty() && line.filterWorkbenchKeyword.empty() && line.filterCategoryKeyword.empty()) {
					found = true;
				}

				/*if (found && !line.workbenchKeyword.empty() && line.workbenchKeyword != "none") {
					RE::TESForm* currentform = nullptr;
					std::string string_form = line.workbenchKeyword;
					currentform = GetFormFromIdentifier(string_form);
					if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
						curobj->benchKeyword = (RE::BGSKeyword*)currentform;
						logger::debug(FMT_STRING("cobj formid: {:08X} changed workbench keyword to {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
					} else if (line.workbenchKeyword == "null") {
						curobj->benchKeyword = nullptr;
						logger::debug(FMT_STRING("cobj formid: {:08X} changed workbench keyword to null (none)"), curobj->formID);
					}
				}

				if (found && !line.categoryKeywordToAdd.empty()) {
					for (size_t i = 0; i < line.categoryKeywordToAdd.size(); i++) {
						RE::TESForm* currentform = nullptr;
						std::string string_form = line.categoryKeywordToAdd[i];
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
							if (!curobj->filterKeywords.HasKeyword((RE::BGSKeyword*)currentform)) {
								curobj->filterKeywords.AddKeywordRecipe((RE::BGSKeyword*)currentform);
								logger::debug(FMT_STRING("cobj formid: {:08X} added keyword {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
							}
							if (curobj->filterKeywords.HasKeyword((RE::BGSKeyword*)currentform)) {
								logger::debug(FMT_STRING("cobj formid: {:08X} has added keyword {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
							}
						}
					}
				}

				if (found && !line.categoryKeywordToRemove.empty()) {
					for (size_t i = 0; i < line.categoryKeywordToRemove.size(); i++) {
						RE::TESForm* currentform = nullptr;
						std::string string_form = line.categoryKeywordToRemove[i];
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
							curobj->filterKeywords.RemoveKeywordRecipe((RE::BGSKeyword*)currentform);
							logger::debug(FMT_STRING("cobj formid: {:08X} removed keyword {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
						}
					}
				}*/
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

	void* patch(COBJ::line_content line, RE::BGSConstructibleObject* curobj)
	{
		if (!line.workbenchKeyword.empty() && line.workbenchKeyword != "none") {
			RE::TESForm* currentform = nullptr;
			std::string string_form = line.workbenchKeyword;
			currentform = GetFormFromIdentifier(string_form);
			if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
				curobj->benchKeyword = (RE::BGSKeyword*)currentform;
				logger::debug(FMT_STRING("cobj formid: {:08X} changed workbench keyword to {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
			} else if (line.workbenchKeyword == "null") {
				curobj->benchKeyword = nullptr;
				logger::debug(FMT_STRING("cobj formid: {:08X} changed workbench keyword to null (none)"), curobj->formID);
			}
		}

		if (!line.categoryKeywordToAdd.empty()) {
			for (size_t i = 0; i < line.categoryKeywordToAdd.size(); i++) {
				RE::TESForm* currentform = nullptr;
				std::string string_form = line.categoryKeywordToAdd[i];
				currentform = GetFormFromIdentifier(string_form);
				if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
					if (!curobj->filterKeywords.HasKeyword((RE::BGSKeyword*)currentform)) {
						curobj->filterKeywords.AddKeywordRecipe((RE::BGSKeyword*)currentform);
						logger::debug(FMT_STRING("cobj formid: {:08X} added keyword {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
					}
					if (curobj->filterKeywords.HasKeyword((RE::BGSKeyword*)currentform)) {
						logger::debug(FMT_STRING("cobj formid: {:08X} has added keyword {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
					}
				}
			}
		}

		if (!line.categoryKeywordToRemove.empty()) {
			for (size_t i = 0; i < line.categoryKeywordToRemove.size(); i++) {
				RE::TESForm* currentform = nullptr;
				std::string string_form = line.categoryKeywordToRemove[i];
				currentform = GetFormFromIdentifier(string_form);
				if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
					curobj->filterKeywords.RemoveKeywordRecipe((RE::BGSKeyword*)currentform);
					logger::debug(FMT_STRING("cobj formid: {:08X} removed keyword {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
				}
			}
		}
	}

	//void* readConfig()
	//{
	//	logger::debug("Reading config and create forms...");
	//
	//	char skipChar = '/';
	//	std::string extension = ".ini";
	//	DIR* dir;
	//	struct dirent* ent;
	//	std::string folder = ".\\Data\\F4se\\Plugins\\RobCo_Patcher\\constructibleObject\\";
	//
	//	if ((dir = opendir(folder.c_str())) != NULL) {
	//		while ((ent = readdir(dir)) != NULL) {
	//			if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
	//				logger::info("*********************************");
	//				logger::info(FMT_STRING("Config file {} found."), ent->d_name);
	//				logger::info("*********************************");
	//			}
	//			std::string fileName = ent->d_name;
	//			size_t pos = fileName.find(extension);
	//			if (pos != std::string::npos) {
	//				fileName = fileName.substr(0, pos);
	//				const char* modname = fileName.c_str();
	//
	//				if ((strstr(modname, ".esp") != nullptr || strstr(modname, ".esl") != nullptr || strstr(modname, ".esm") != nullptr)) {
	//					if (!IsPluginInstalled(modname)) {
	//						logger::info(FMT_STRING("{} not found or is not a valid plugin file, skipping config file."), modname);
	//						continue;
	//					}
	//				}
	//
	//				std::string line;
	//				std::ifstream infile;
	//				std::list<line_content> tokens;
	//				infile.open(folder + ent->d_name);
	//				while (std::getline(infile, line)) {
	//					if (line[0] == skipChar) {
	//						continue;
	//					}
	//
	//					if (line.empty()) {
	//						continue;
	//					}
	//
	//					tokens.push_back(create_patch_instruction(line));
	//				}
	//				infile.close();
	//				process_patch_instructions(tokens);
	//			}
	//		}
	//		closedir(dir);
	//	} else {
	//		logger::info("Couldn't find cobj dir.");
	//	}
	//
	//	return 0;
	//}

}

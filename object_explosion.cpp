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

		if (!line.objects.empty()) {
			continue;
		}

		for (const auto& curobj : objectArray) {

			bool found = false;




			if (line.objects.empty()) {
				found = true;
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
		return nullptr;
	}

}

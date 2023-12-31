#include "object_npcs.h"

namespace NPCS
{


	struct patch_instruction create_patch_instruction(const std::string& line)
	{
		patch_instruction l;
		// extract npcs
		// extract objects
		std::regex objects_regex("filterByNpcs\\s*=([^:]+)", regex::icase);
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
			l.object = objects;
		}

		// extract objectsExcluded
		std::regex objectsExcluded_regex("filterByNpcsExcluded\\s*=([^:]+)", regex::icase);
		std::smatch objectsExcluded_match;
		std::regex_search(line, objectsExcluded_match, objectsExcluded_regex);
		std::vector<std::string> objectsExcluded;
		if (objectsExcluded_match.empty() || objectsExcluded_match[1].str().empty()) {
			//empty
		} else {
			std::string objectsExcluded_str = objectsExcluded_match[1];
			std::regex objectsExcluded_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator objectsExcluded_iterator(objectsExcluded_str.begin(), objectsExcluded_str.end(), objectsExcluded_list_regex);
			std::sregex_iterator objectsExcluded_end;
			while (objectsExcluded_iterator != objectsExcluded_end) {
				std::string tempVar = (*objectsExcluded_iterator)[0].str();
				tempVar.erase(tempVar.begin(), std::find_if_not(tempVar.begin(), tempVar.end(), ::isspace));
				tempVar.erase(std::find_if_not(tempVar.rbegin(), tempVar.rend(), ::isspace).base(), tempVar.end());
				//logger::info(FMT_STRING("Race: {}"), race);
				if (tempVar != "none") {
					objectsExcluded.push_back(tempVar);
				}
				++objectsExcluded_iterator;
			}
			l.objectExcluded = objectsExcluded;
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

		// extract races
		std::regex races_regex("filterByRaces\\s*=([^:]+)", regex::icase);
		std::smatch races_match;
		std::regex_search(line, races_match, races_regex);
		std::vector<std::string> races;
		if (races_match.empty() || races_match[1].str().empty()) {
			//empty
		} else {
			std::string races_str = races_match[1];
			std::regex races_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator races_iterator(races_str.begin(), races_str.end(), races_list_regex);
			std::sregex_iterator races_end;
			while (races_iterator != races_end) {
				std::string race = (*races_iterator)[0].str();
				race.erase(race.begin(), std::find_if_not(race.begin(), race.end(), ::isspace));
				race.erase(std::find_if_not(race.rbegin(), race.rend(), ::isspace).base(), race.end());
				//logger::info(FMT_STRING("Race: {}"), race);
				if (race != "none") {
					races.push_back(race);
				}
				++races_iterator;
			}
			l.races = races;
		}

				// extract Class
		std::regex filterClass_regex("filterByClass\\s*=([^:]+)", regex::icase);
		std::smatch filterClass_match;
		std::regex_search(line, filterClass_match, filterClass_regex);
		std::vector<std::string> Class;
		if (filterClass_match.empty() || filterClass_match[1].str().empty()) {
			//empty
		} else {
			std::string Class_str = filterClass_match[1];
			std::regex Class_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator Class_iterator(Class_str.begin(), Class_str.end(), Class_list_regex);
			std::sregex_iterator Class_end;
			while (Class_iterator != Class_end) {
				std::string race = (*Class_iterator)[0].str();
				race.erase(race.begin(), std::find_if_not(race.begin(), race.end(), ::isspace));
				race.erase(std::find_if_not(race.rbegin(), race.rend(), ::isspace).base(), race.end());
				//logger::info(FMT_STRING("Race: {}"), race);
				if (race != "none") {
					Class.push_back(race);
				}
				++Class_iterator;
			}
			l.filterClass = Class;
		}

				// extract Faction
		std::regex FactionAnd_regex("filterByFactions\\s*=([^:]+)", regex::icase);
		std::smatch FactionAnd_match;
		std::regex_search(line, FactionAnd_match, FactionAnd_regex);
		std::vector<std::string> Faction;
		if (FactionAnd_match.empty() || FactionAnd_match[1].str().empty()) {
			//empty
		} else {
			std::string Faction_str = FactionAnd_match[1];
			std::regex Faction_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator Faction_iterator(Faction_str.begin(), Faction_str.end(), Faction_list_regex);
			std::sregex_iterator Faction_end;
			while (Faction_iterator != Faction_end) {
				std::string keyword = (*Faction_iterator)[0].str();
				keyword.erase(keyword.begin(), std::find_if_not(keyword.begin(), keyword.end(), ::isspace));
				keyword.erase(std::find_if_not(keyword.rbegin(), keyword.rend(), ::isspace).base(), keyword.end());
				if (keyword != "none") {
					Faction.push_back(keyword);
				}
				++Faction_iterator;
			}
			l.filterFactions = Faction;
		}

		// extract Faction
		std::regex FactionOr_regex("filterByFactionsOr\\s*=([^:]+)", regex::icase);
		std::smatch FactionOr_match;
		std::regex_search(line, FactionOr_match, FactionOr_regex);
		std::vector<std::string> FactionOr;
		if (FactionOr_match.empty() || FactionOr_match[1].str().empty()) {
			//empty
		} else {
			std::string FactionOr_str = FactionOr_match[1];
			std::regex FactionOr_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator FactionOr_iterator(FactionOr_str.begin(), FactionOr_str.end(), FactionOr_list_regex);
			std::sregex_iterator FactionOr_end;
			while (FactionOr_iterator != FactionOr_end) {
				std::string keyword = (*FactionOr_iterator)[0].str();
				keyword.erase(keyword.begin(), std::find_if_not(keyword.begin(), keyword.end(), ::isspace));
				keyword.erase(std::find_if_not(keyword.rbegin(), keyword.rend(), ::isspace).base(), keyword.end());
				if (keyword != "none") {
					FactionOr.push_back(keyword);
				}
				++FactionOr_iterator;
			}
			l.filterFactionsOr = FactionOr;
		}

		// extract Faction
		std::regex FactionExcluded_regex("filterByFactionsExcluded\\s*=([^:]+)", regex::icase);
		std::smatch FactionExcluded_match;
		std::regex_search(line, FactionExcluded_match, FactionExcluded_regex);
		std::vector<std::string> FactionExcluded;
		if (FactionExcluded_match.empty() || FactionExcluded_match[1].str().empty()) {
			//empty
		} else {
			std::string FactionExcluded_str = FactionExcluded_match[1];
			std::regex FactionExcluded_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator FactionExcluded_iterator(FactionExcluded_str.begin(), FactionExcluded_str.end(), FactionExcluded_list_regex);
			std::sregex_iterator FactionExcluded_end;
			while (FactionExcluded_iterator != FactionExcluded_end) {
				std::string keyword = (*FactionExcluded_iterator)[0].str();
				keyword.erase(keyword.begin(), std::find_if_not(keyword.begin(), keyword.end(), ::isspace));
				keyword.erase(std::find_if_not(keyword.rbegin(), keyword.rend(), ::isspace).base(), keyword.end());
				if (keyword != "none") {
					FactionExcluded.push_back(keyword);
				}
				++FactionExcluded_iterator;
			}
			l.filterFactionsExcluded = FactionExcluded;
		}

		// extract autoCalcStats
		std::regex list_regex("setAutoCalcStats\\s*=([^:]+)", regex::icase);
		std::smatch listmatch;
		std::regex_search(line, listmatch, list_regex);
		// extract the value after the equals sign
		if (listmatch.empty() || listmatch[1].str().empty()) {
			l.calcStats = "none";
		} else {
			std::string tempString = listmatch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.calcStats = tempString;
		}

		// extract pclevelmult
		std::regex pclevelmultlist_regex("setPcLevelMult\\s*=([^:]+)", regex::icase);
		std::smatch pclevelmultlistmatch;
		std::regex_search(line, pclevelmultlistmatch, pclevelmultlist_regex);
		// extract the value after the equals sign
		if (pclevelmultlistmatch.empty() || pclevelmultlistmatch[1].str().empty()) {
			l.kPCLevelMult = "none";
		} else {
			std::string tempString = pclevelmultlistmatch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.kPCLevelMult = tempString;
		}

		// extract Essential
		std::regex essentiallist_regex("setEssential\\s*=([^:]+)", regex::icase);
		std::smatch essentiallistmatch;
		std::regex_search(line, essentiallistmatch, essentiallist_regex);
		// extract the value after the equals sign
		if (essentiallistmatch.empty() || essentiallistmatch[1].str().empty()) {
			l.kEssential = "none";
		} else {
			std::string tempString = essentiallistmatch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.kEssential = tempString;
		}

		// extract Protected
		std::regex Protectedlist_regex("setProtected\\s*=([^:]+)", regex::icase);
		std::smatch Protectedlistmatch;
		std::regex_search(line, Protectedlistmatch, Protectedlist_regex);
		// extract the value after the equals sign
		if (Protectedlistmatch.empty() || Protectedlistmatch[1].str().empty()) {
			l.kProtected = "none";
		} else {
			std::string tempString = Protectedlistmatch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.kProtected = tempString;
		}

		// extract getLevelRange
		std::regex levelRange_regex("levelRange\\s*=\\s*(\\d+)\\s*~\\s*(\\d+)", regex::icase);
		std::smatch levelRange;
		std::regex_search(line, levelRange, levelRange_regex);
		if (levelRange.empty() || levelRange.size() < 3) {
			l.level_min = "none";
			l.level_max = "none";
		} else {
			l.level_min = levelRange[1].str();
			l.level_max = levelRange[2].str();
		}

		// extract avifs
		std::regex avifs_regex("changeAVIFS\\s*=([^:]+)", regex::icase);
		std::smatch avifs_match;
		std::regex_search(line, avifs_match, avifs_regex);
		std::vector<std::string> avifs_before_eq;
		std::vector<float> avifs_min_values;
		std::vector<float> avifs_max_values;
		if (avifs_match.empty() || avifs_match[1].str().empty()) {
			//empty
		} else {
			std::string avifs_str = avifs_match[1];
			std::regex avifs_list_regex("([^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8})\\s*=\\s*([\\d.]+)(?:\\s*~\\s*([\\d.]+))?", regex::icase);
			std::sregex_iterator avifs_iterator(avifs_str.begin(), avifs_str.end(), avifs_list_regex);
			std::sregex_iterator avifs_end;
			while (avifs_iterator != avifs_end) {
				std::string avif = (*avifs_iterator)[1].str();
				avif.erase(avif.begin(), std::find_if_not(avif.begin(), avif.end(), ::isspace));
				avif.erase(std::find_if_not(avif.rbegin(), avif.rend(), ::isspace).base(), avif.end());

				if (avif == "none") {
					break;
				}

				avifs_before_eq.push_back(avif);
				avifs_min_values.push_back(std::stof((*avifs_iterator)[2]));
				if ((*avifs_iterator)[3] != "") {
					avifs_max_values.push_back(std::stof((*avifs_iterator)[3]));
				} else {
					avifs_max_values.push_back(std::stof((*avifs_iterator)[2]));
				}
				std::string val1 = ((*avifs_iterator)[2]);
				std::string val2 = ((*avifs_iterator)[3] != "") ? ((*avifs_iterator)[3]) : ((*avifs_iterator)[2]);
				//logger::info(FMT_STRING("avif: {}"), avif);
				//logger::info(FMT_STRING("value1: {}"), val1);
				//logger::info(FMT_STRING("value2: {}"), val2);
				++avifs_iterator;
			}
			l.avifs = avifs_before_eq;
			l.values1 = avifs_min_values;
			l.values2 = avifs_max_values;
		}

		// extract Faction
		std::regex Faction_regex("factionsToAdd\\s*=([^:]+)", regex::icase);
		std::smatch Faction_match;
		std::regex_search(line, Faction_match, Faction_regex);
		std::vector<std::string> Faction_before_eq;
		std::vector<float> Faction_min_values;
		std::vector<float> Faction_max_values;
		if (Faction_match.empty() || Faction_match[1].str().empty()) {
			//empty
		} else {
			std::string Faction_str = Faction_match[1];
			std::regex Faction_list_regex("([^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8})\\s*=\\s*([\\d.]+)(?:\\s*~\\s*([\\d.]+))?", regex::icase);
			std::sregex_iterator Faction_iterator(Faction_str.begin(), Faction_str.end(), Faction_list_regex);
			std::sregex_iterator Faction_end;
			while (Faction_iterator != Faction_end) {
				std::string avif = (*Faction_iterator)[1].str();
				avif.erase(avif.begin(), std::find_if_not(avif.begin(), avif.end(), ::isspace));
				avif.erase(std::find_if_not(avif.rbegin(), avif.rend(), ::isspace).base(), avif.end());

				if (avif == "none") {
					break;
				}

				Faction_before_eq.push_back(avif);
				Faction_min_values.push_back(std::stof((*Faction_iterator)[2]));
				if ((*Faction_iterator)[3] != "") {
					Faction_max_values.push_back(std::stof((*Faction_iterator)[3]));
				} else {
					Faction_max_values.push_back(std::stof((*Faction_iterator)[2]));
				}
				std::string val1 = ((*Faction_iterator)[2]);
				std::string val2 = ((*Faction_iterator)[3] != "") ? ((*Faction_iterator)[3]) : ((*Faction_iterator)[2]);
				//logger::info(FMT_STRING("avif: {}"), avif);
				//logger::info(FMT_STRING("value1: {}"), val1);
				//logger::info(FMT_STRING("value2: {}"), val2);
				++Faction_iterator;
			}
			l.factionsToAdd = Faction_before_eq;
			l.factionsToAddRank1 = Faction_min_values;
			l.factionsToAddRank2 = Faction_max_values;
		}

		// extract keywordsToAdd
		std::regex keywordsToAdd_regex("keywordsToAdd\\s*=([^:]+)", regex::icase);
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
			l.keywordsToAdd = keywordsToAdd;
		}

		// extract keywordsToRemove
		std::regex keywordsToRemove_regex("keywordsToRemove\\s*=([^:]+)", regex::icase);
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
			l.keywordsToRemove = keywordsToRemove;
		}

		// extract factionsToRemove
		std::regex factionsToRemove_regex("factionsToRemove\\s*=([^:]+)", regex::icase);
		std::smatch factionsToRemove_match;
		std::regex_search(line, factionsToRemove_match, factionsToRemove_regex);
		std::vector<std::string> factionsToRemove;
		if (factionsToRemove_match.empty() || factionsToRemove_match[1].str().empty()) {
			//empty
		} else {
			std::string factionsToRemove_str = factionsToRemove_match[1];
			std::regex factionsToRemove_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator factionsToRemove_iterator(factionsToRemove_str.begin(), factionsToRemove_str.end(), factionsToRemove_list_regex);
			std::sregex_iterator factionsToRemove_end;
			while (factionsToRemove_iterator != factionsToRemove_end) {
				std::string keywordToRemove = (*factionsToRemove_iterator)[0].str();
				keywordToRemove.erase(keywordToRemove.begin(), std::find_if_not(keywordToRemove.begin(), keywordToRemove.end(), ::isspace));
				keywordToRemove.erase(std::find_if_not(keywordToRemove.rbegin(), keywordToRemove.rend(), ::isspace).base(), keywordToRemove.end());
				if (keywordToRemove != "none") {
					//logger::info(FMT_STRING("factionsToRemove: {}"), keywordToRemove);
					factionsToRemove.push_back(keywordToRemove);
				}
				++factionsToRemove_iterator;
			}
			l.factionsToRemove = factionsToRemove;
		}

		// extract perksToAdd
		std::regex perksToAdd_regex("perksToAdd\\s*=([^:]+)", regex::icase);
		std::smatch perksToAdd_match;
		std::regex_search(line, perksToAdd_match, perksToAdd_regex);
		std::vector<std::string> perksToAdd;
		if (perksToAdd_match.empty() || perksToAdd_match[1].str().empty()) {
			//empty
		} else {
			std::string perksToAdd_str = perksToAdd_match[1];
			std::regex perksToAdd_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator perksToAdd_iterator(perksToAdd_str.begin(), perksToAdd_str.end(), perksToAdd_list_regex);
			std::sregex_iterator perksToAdd_end;
			while (perksToAdd_iterator != perksToAdd_end) {
				std::string perkToAdd = (*perksToAdd_iterator)[0].str();
				perkToAdd.erase(perkToAdd.begin(), std::find_if_not(perkToAdd.begin(), perkToAdd.end(), ::isspace));
				perkToAdd.erase(std::find_if_not(perkToAdd.rbegin(), perkToAdd.rend(), ::isspace).base(), perkToAdd.end());
				if ((*perksToAdd_iterator)[0].str() != "none") {
					//logger::info(FMT_STRING("perksToAdd: {}"), perkToAdd);
					perksToAdd.push_back(perkToAdd);
				}
				++perksToAdd_iterator;
			}
			l.perksToAdd = perksToAdd;
		}

		std::regex objectsToAdd_regex("objectsToAdd\\s*=([^:]+)", regex::icase);
		std::smatch objectsToAdd_match;
		std::regex_search(line, objectsToAdd_match, objectsToAdd_regex);
		std::vector<std::string> objectsToAdd;
		if (objectsToAdd_match.empty() || objectsToAdd_match[1].str().empty()) {
			//empty
		} else {
			std::string objectsToAdd_str = objectsToAdd_match[1];
			std::regex pattern("([^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8})\\s*=\\s*([^,]+)", regex::icase);
			std::smatch match;

			auto begin = std::sregex_iterator(objectsToAdd_str.begin(), objectsToAdd_str.end(), pattern);
			auto end = std::sregex_iterator();

			for (std::sregex_iterator i = begin; i != end; ++i) {
				std::smatch match = *i;
				l.objectsToAdd.push_back(match[1]);
				l.objectsToAddValue.push_back(match[2]);
				//logger::debug(FMT_STRING("Match: {} {}"), match[1].str(), match[2].str());
			}
		}

		// extract ObjectsToRemove
		std::regex ObjectsToRemove_regex("ObjectsToRemove\\s*=([^:]+)", regex::icase);
		std::smatch ObjectsToRemove_match;
		std::regex_search(line, ObjectsToRemove_match, ObjectsToRemove_regex);
		std::vector<std::string> ObjectsToRemove;
		if (ObjectsToRemove_match.empty() || ObjectsToRemove_match[1].str().empty()) {
			//empty
		} else {
			std::string ObjectsToRemove_str = ObjectsToRemove_match[1];
			std::regex ObjectsToRemove_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator ObjectsToRemove_iterator(ObjectsToRemove_str.begin(), ObjectsToRemove_str.end(), ObjectsToRemove_list_regex);
			std::sregex_iterator ObjectsToRemove_end;
			while (ObjectsToRemove_iterator != ObjectsToRemove_end) {
				std::string keywordToRemove = (*ObjectsToRemove_iterator)[0].str();
				keywordToRemove.erase(keywordToRemove.begin(), std::find_if_not(keywordToRemove.begin(), keywordToRemove.end(), ::isspace));
				keywordToRemove.erase(std::find_if_not(keywordToRemove.rbegin(), keywordToRemove.rend(), ::isspace).base(), keywordToRemove.end());
				if (keywordToRemove != "none") {
					//logger::info(FMT_STRING("ObjectsToRemove: {}"), keywordToRemove);
					ObjectsToRemove.push_back(keywordToRemove);
				}
				++ObjectsToRemove_iterator;
			}
			l.objectsToRemove = ObjectsToRemove;
		}

		// extract Outfit
		std::regex Outfit_regex("outfitDefault\\s*=([^:]+)", regex::icase);
		std::smatch outfitDefaultmatch;
		std::regex_search(line, outfitDefaultmatch, Outfit_regex);
		// extract the value after the equals sign
		if (outfitDefaultmatch.empty() || outfitDefaultmatch[1].str().empty()) {
			l.outfitDefault = "none";
		} else {
			std::string tempString = outfitDefaultmatch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.outfitDefault = tempString;
		}

				// extract Outfit
		std::regex OutfitSleep_regex("outfitSleep\\s*=([^:]+)", regex::icase);
		std::smatch outfitSleepmatch;
		std::regex_search(line, outfitSleepmatch, OutfitSleep_regex);
		// extract the value after the equals sign
		if (outfitSleepmatch.empty() || outfitSleepmatch[1].str().empty()) {
			l.outfitSleep = "none";
		} else {
			std::string tempString = outfitSleepmatch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.outfitSleep = tempString;
		}

		// extract deathItem
		std::regex DeathItem_regex("deathItem\\s*=([^:]+)", regex::icase);
		std::smatch DeathItemmatch;
		std::regex_search(line, DeathItemmatch, DeathItem_regex);
		// extract the value after the equals sign
		if (DeathItemmatch.empty() || DeathItemmatch[1].str().empty()) {
			l.deathItem = "none";
		} else {
			std::string tempString = DeathItemmatch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.deathItem = tempString;
		}

		// extract Skin
		std::regex skin_regex("skin\\s*=([^:]+)", regex::icase);
		std::smatch skinmatch;
		std::regex_search(line, skinmatch, skin_regex);
		// extract the value after the equals sign
		if (skinmatch.empty() || skinmatch[1].str().empty()) {
			l.skin = "none";
		} else {
			std::string tempString = skinmatch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.skin = tempString;
		}

		// extract Race
		std::regex Race_regex("race\\s*=([^:]+)", regex::icase);
		std::smatch Racematch;
		std::regex_search(line, Racematch, Race_regex);
		// extract the value after the equals sign
		if (Racematch.empty() || Racematch[1].str().empty()) {
			l.race = "none";
		} else {
			std::string tempString = Racematch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.race = tempString;
		}

				// extract powerArmorStand
		std::regex powerArmorStand_regex("powerArmorStand\\s*=([^:]+)", regex::icase);
		std::smatch powerArmorStandmatch;
		std::regex_search(line, powerArmorStandmatch, powerArmorStand_regex);
		// extract the value after the equals sign
		if (powerArmorStandmatch.empty() || powerArmorStandmatch[1].str().empty()) {
			l.powerArmorStand = "none";
		} else {
			std::string tempString = powerArmorStandmatch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.powerArmorStand = tempString;
		}

				// extract Class
		std::regex Class_regex("class\\s*=([^:]+)", regex::icase);
		std::smatch Classmatch;
		std::regex_search(line, Classmatch, Class_regex);
		// extract the value after the equals sign
		if (Classmatch.empty() || Classmatch[1].str().empty()) {
			l.Class = "none";
		} else {
			std::string tempString = Classmatch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.Class = tempString;
		}


		// extract xpOffsetValue
		std::regex xpOffsetValue_regex("xpValueOffset\\s*=([^:]+)", regex::icase);
		std::smatch xpmatch;
		std::regex_search(line, xpmatch, xpOffsetValue_regex);
		// extract the value after the equals sign
		if (xpmatch.empty() || xpmatch[1].str().empty()) {
			l.xpValueOffset = "none";
		} else {
			std::string tempString = xpmatch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.xpValueOffset = tempString;
		}

				// extract level
		std::regex level_regex("level\\s*=([^:]+)", regex::icase);
		std::smatch lvlmatch;
		std::regex_search(line, lvlmatch, level_regex);
		// extract the value after the equals sign
		if (lvlmatch.empty() || lvlmatch[1].str().empty()) {
			l.level = "none";
		} else {
			std::string tempString = lvlmatch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.level = tempString;
		}

				// extract calcLevelMin
		std::regex calcLevelMin_regex("calcLevelMin\\s*=([^:]+)", regex::icase);
		std::smatch lminmatch;
		std::regex_search(line, lminmatch, calcLevelMin_regex);
		// extract the value after the equals sign
		if (lminmatch.empty() || lminmatch[1].str().empty()) {
			l.calcLevelMin = "none";
		} else {
			std::string tempString = lminmatch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.calcLevelMin = tempString;
		}

				// extract calcLevelMax
		std::regex calcLevelMax_regex("calcLevelMax\\s*=([^:]+)", regex::icase);
		std::smatch lmaxmatch;
		std::regex_search(line, lmaxmatch, calcLevelMax_regex);
		// extract the value after the equals sign
		if (lmaxmatch.empty() || lmaxmatch[1].str().empty()) {
			l.calcLevelMax = "none";
		} else {
			std::string tempString = lmaxmatch[1].str();
			tempString.erase(tempString.begin(), std::find_if_not(tempString.begin(), tempString.end(), ::isspace));
			tempString.erase(std::find_if_not(tempString.rbegin(), tempString.rend(), ::isspace).base(), tempString.end());
			l.calcLevelMax = tempString;
		}

				// extract spellsToAdd
		std::regex spellsToAdd_regex("spellsToAdd\\s*=([^:]+)", regex::icase);
		std::smatch spellsToAdd_match;
		std::regex_search(line, spellsToAdd_match, spellsToAdd_regex);
		std::vector<std::string> spellsToAdd;
		if (spellsToAdd_match.empty() || spellsToAdd_match[1].str().empty()) {
			//empty
		} else {
			std::string spellsToAdd_str = spellsToAdd_match[1];
			std::regex spellsToAdd_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator spellsToAdd_iterator(spellsToAdd_str.begin(), spellsToAdd_str.end(), spellsToAdd_list_regex);
			std::sregex_iterator spellsToAdd_end;
			while (spellsToAdd_iterator != spellsToAdd_end) {
				std::string spellToAdd = (*spellsToAdd_iterator)[0].str();
				spellToAdd.erase(spellToAdd.begin(), std::find_if_not(spellToAdd.begin(), spellToAdd.end(), ::isspace));
				spellToAdd.erase(std::find_if_not(spellToAdd.rbegin(), spellToAdd.rend(), ::isspace).base(), spellToAdd.end());
				if ((*spellsToAdd_iterator)[0].str() != "none") {
					//logger::info(FMT_STRING("spellsToAdd: {}"), spellToAdd);
					spellsToAdd.push_back(spellToAdd);
				}
				++spellsToAdd_iterator;
			}
			l.spellsToAdd = spellsToAdd;
		}

		// extract isFemale
		std::regex isFemale_regex("filterByGender\\s*=([^:]+)", regex::icase);
		std::smatch isfemalematch;
		std::regex_search(line, isfemalematch, isFemale_regex);
		// extract the value after the equals sign
		if (isfemalematch.empty() || isfemalematch[1].str().empty()) {
			l.isFemale = "none";
		} else {
			std::string isfemalevalue = isfemalematch[1].str();
			isfemalevalue.erase(isfemalevalue.begin(), std::find_if_not(isfemalevalue.begin(), isfemalevalue.end(), ::isspace));
			isfemalevalue.erase(std::find_if_not(isfemalevalue.rbegin(), isfemalevalue.rend(), ::isspace).base(), isfemalevalue.end());
			l.isFemale = isfemalevalue;
		}

		// extract fullName
		std::regex fullName_regex("fullName\\s*=\\s*~([^~]+?)\\s*~");
		std::smatch namematch;
		std::regex_search(line, namematch, fullName_regex);
		// extract the value after the equals sign
		if (namematch.empty() || namematch[1].str().empty()) {
			l.fullName = "none";
		} else {
			std::string namevalue = namematch[1].str();
			namevalue.erase(namevalue.begin(), std::find_if_not(namevalue.begin(), namevalue.end(), ::isspace));
			namevalue.erase(std::find_if_not(namevalue.rbegin(), namevalue.rend(), ::isspace).base(), namevalue.end());
			l.fullName = namevalue;
		}


		logger::debug(FMT_STRING("npcs: {} races: {}  keywords: {}  avifs: {} keywordsToAdd: {} perksToAdd {}"), l.object.size(), l.races.size(), l.keywords.size(), l.avifs.size(), l.keywordsToAdd.size(), l.perksToAdd.size());
		//logger::info("returning patch instructions");
		return l;
	}

	void process_patch_instructions(const std::list<patch_instruction>& tokens)
	{
		logger::debug("processing patch instructions");
		const auto dataHandler = RE::TESDataHandler::GetSingleton();
		RE::BSTArray<RE::TESNPC*> NPCArray = dataHandler->GetFormArray<RE::TESNPC>();

		for (const auto& line : tokens) {
			//logger::info("processing config line");
			for (const auto& curobj : NPCArray) {
				bool found = false;
				bool keywordAnd = false;
				bool keywordOr = false;
				bool factionAnd = false;
				bool factionOr = false;
				//curobj.
				if (!line.object.empty()) {
					//logger::info("npc not empty");
					for (const auto& npcstring : line.object) {
						RE::TESForm* currentform = nullptr;
						RE::TESNPC* npc = nullptr;

						std::string string_form = npcstring;
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kNPC_) {
							npc = (RE::TESNPC*)currentform;

							if (curobj->formID == npc->formID) {
								found = true;
								//logger::info("NPC found.");
								break;
							}
						}
					}
				}

				if (!line.filterClass.empty()) {
					//logger::info("npc not empty");
					for (const auto& npcstring : line.filterClass) {
						RE::TESForm* currentform = nullptr;
						RE::TESClass* npc = nullptr;

						std::string string_form = npcstring;
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kCLAS) {
							npc = (RE::TESClass*)currentform;

							if (curobj->cl->formID == npc->formID) {
								found = true;
								//logger::info("NPC found.");
								break;
							}
						}
					}
				}

				
				if (!found && !line.races.empty() && curobj->formID != 0x000007 && !curobj->HasKeyword(PlayerKeyword)) {
					//logger::info("race not empty");
					for (const auto& racestring : line.races) {
						RE::TESForm* currentform = nullptr;
						RE::TESRace* race = nullptr;

						std::string string_form = racestring;
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kRACE) {
							race = (RE::TESRace*)currentform;

							if (curobj->formRace == race) {
								found = true;
								//logger::debug(FMT_STRING("Found a matching npc by race({:08X} {}). {:08X} {}"), race->formID, race->fullName, curobj->formID, curobj->fullName );
								break;
							}
						}
					}
				}

				if (!line.keywords.empty() && curobj->formID != 0x000007 && !curobj->HasKeyword(PlayerKeyword)) {
					//logger::info("keywords not empty");
					for (const auto& keywordstring : line.keywords) {
						RE::TESForm* currentform = nullptr;
						RE::BGSKeyword* keyword = nullptr;

						std::string string_form = keywordstring;
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
							keyword = (RE::BGSKeyword*)currentform;

							if (curobj->HasKeyword(keyword) || curobj->baseTemplateForm == nullptr && curobj->formRace->HasKeyword(keyword)) {
								keywordAnd = true;
							} else {
								keywordAnd = false;
								//logger::debug(FMT_STRING("KeywordAnd npc does not have all keywords"));
								break;
							}
							//logger::debug(FMT_STRING("KeywordAnd npc true"));
						}
					}
				} else if (curobj->formID != 0x000007 && !curobj->HasKeyword(PlayerKeyword)) {
					//logger::debug(FMT_STRING("KeywordAnd is empty, we pass true."));
					keywordAnd = true;
				}
				if (!line.keywordsOr.empty() && curobj->formID != 0x000007 && !curobj->HasKeyword(PlayerKeyword)) {
					//logger::info("keywords not empty");
					for (const auto& keywordstring : line.keywordsOr) {
						RE::TESForm* currentform = nullptr;
						RE::BGSKeyword* keyword = nullptr;

						std::string string_form = keywordstring;
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
							keyword = (RE::BGSKeyword*)currentform;

							if (curobj->HasKeyword(keyword) || curobj->baseTemplateForm == nullptr && curobj->formRace->HasKeyword(keyword) ) {
								keywordOr = true;
								//logger::debug(FMT_STRING("KeywordOr has at least one keyword true {:08X} {:08X} race {:08X}"), curobj->formID, keyword->formID, curobj->formRace->formID);
								//logger::info("Keyword found.");
								break;
							}
						}
					}
				} else if (curobj->formID != 0x000007 && !curobj->HasKeyword(PlayerKeyword)) {
					//logger::debug(FMT_STRING("KeywordOr is empty, we pass true."));
					keywordOr = true;
				}

				if (!line.filterFactions.empty() && curobj->formID != 0x000007 && !curobj->HasKeyword(PlayerKeyword)) {
					//logger::info("filterByFaction not empty");
					for (const auto& filterByFactiontring : line.filterFactions) {
						RE::TESForm* currentform = nullptr;
						RE::TESFaction* keyword = nullptr;

						std::string string_form = filterByFactiontring;
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kFACT) {
							keyword = (RE::TESFaction*)currentform;

							if (curobj->hasFaction(keyword)) {
								factionAnd = true;
							} else {
								factionAnd = false;
								//logger::debug(FMT_STRING("KeywordAnd npc does not have all filterByFaction"));
								break;
							}
							//logger::debug(FMT_STRING("KeywordAnd npc true"));
						}
					}
				} else if (curobj->formID != 0x000007 && !curobj->HasKeyword(PlayerKeyword)) {
					//logger::debug(FMT_STRING("KeywordAnd is empty, we pass true."));
					factionAnd = true;
				}

				if (!line.filterFactionsOr.empty() && curobj->formID != 0x000007 && !curobj->HasKeyword(PlayerKeyword)) {
					//logger::info("keywords not empty");
					for (const auto& keywordstring : line.filterFactionsOr) {
						RE::TESForm* currentform = nullptr;
						RE::TESFaction* keyword = nullptr;

						std::string string_form = keywordstring;
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kFACT) {
							keyword = (RE::TESFaction*)currentform;

							if (curobj->hasFaction(keyword) ) {
								factionOr = true;
								//logger::debug(FMT_STRING("NPC has faction {:08X}"), curobj->formID, curobj->fullName);
								//logger::info("Keyword found.");
								break;
							}
						}
					}
				} else if (curobj->formID != 0x000007 && !curobj->HasKeyword(PlayerKeyword)) {
					//logger::debug(FMT_STRING("KeywordAnd is empty, we pass true."));
					factionOr = true;
				}




				if ((!line.keywords.empty() || !line.keywordsOr.empty()) && keywordAnd && keywordOr) {
					logger::debug(FMT_STRING("Found a matching npc by keywords. {:08X} {}"), curobj->formID, curobj->fullName);
					found = true;
				}

				if ((!line.filterFactions.empty() || !line.filterFactionsOr.empty()) && factionAnd && factionOr) {
					//logger::debug(FMT_STRING("Found a matching npc by keywords. {:08X} {}"), curobj->formID, curobj->fullName);
					found = true;
				}

				if (!found && line.object.empty() && line.races.empty() && line.keywords.empty() && line.keywordsOr.empty() && line.filterClass.empty() && line.filterFactions.empty() && line.filterFactionsOr.empty() && curobj->formID != 0x000007 && !curobj->HasKeyword(PlayerKeyword)) {
					found = true;
					//logger::debug(FMT_STRING("Patch Everything but skip Player {:08X}"), curobj->formID);
				}

				if (found && !line.isFemale.empty() && line.isFemale != "none") {
					std::string lowercaseIsFemale = line.isFemale;
					std::transform(lowercaseIsFemale.begin(), lowercaseIsFemale.end(), lowercaseIsFemale.begin(), [](unsigned char c) { return std::tolower(c); });

					if ((lowercaseIsFemale == "female")) {
						if (curobj->actorData.actorBaseFlags & RE::ACTOR_BASE_DATA::Flag::kFemale) {	
							found = true;
							//logger::debug(FMT_STRING("is female {:08X} {}"), curobj->formID, curobj->fullName);
						} else {
							found = false;
							//logger::debug(FMT_STRING("is not female {:08X} {}"), curobj->formID, curobj->fullName);
						}
					} else if ((lowercaseIsFemale == "male")) {
						if (!(curobj->actorData.actorBaseFlags & RE::ACTOR_BASE_DATA::Flag::kFemale)) {
							//logger::debug(FMT_STRING("is male {:08X} {}"), curobj->formID, curobj->fullName);
							found = true;
						} else {
							//logger::debug(FMT_STRING("is not male {:08X} {}"), curobj->formID, curobj->fullName);
							found = false;
						}
					}
				}

				if (!line.keywordsExcluded.empty() && curobj->formID != 0x000007 && !curobj->HasKeyword(PlayerKeyword)) {
					//logger::info("keywords not empty");
					for (const auto& keywordstring : line.keywordsExcluded) {
						RE::TESForm* currentform = nullptr;
						RE::BGSKeyword* keyword = nullptr;

						std::string string_form = keywordstring;
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
							keyword = (RE::BGSKeyword*)currentform;

							if (curobj->HasKeyword(keyword) || curobj->baseTemplateForm == nullptr && curobj->formRace->HasKeyword(keyword)) {
								found = false;
								//logger::debug(FMT_STRING("KeywordExcluded has a keyword that is excluded.{:08X}"), keyword->formID);
								//logger::info("Keyword found.");
								break;
							}
						}
					}
				}

				if (!line.filterFactionsExcluded.empty() && curobj->formID != 0x000007 && !curobj->HasKeyword(PlayerKeyword)) {
					//logger::info("factions not empty");
					for (const auto& factionstring : line.filterFactionsExcluded) {
						RE::TESForm* currentform = nullptr;
						RE::TESFaction* keyword = nullptr;

						std::string string_form = factionstring;
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kFACT) {
							keyword = (RE::TESFaction*)currentform;

							if (curobj->hasFaction(keyword)) {
								found = false;
								//logger::debug(FMT_STRING("KeywordExcluded has a keyword that is excluded.{:08X}"), keyword->formID);
								//logger::info("Keyword found.");
								break;
							}
						}
					}
				}

				if (!line.objectExcluded.empty()) {
					//logger::info("npc not empty");
					for (const auto& npcstring : line.objectExcluded) {
						RE::TESForm* currentform = nullptr;
						RE::TESNPC* npc = nullptr;

						std::string string_form = npcstring;
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kNPC_) {
							npc = (RE::TESNPC*)currentform;

							if (curobj->formID == npc->formID) {
								found = false;
								//logger::info("NPC found.");
								break;
							}
						}
					}
				}

				if (found && !line.calcStats.empty() && line.calcStats != "none") {
					if (line.calcStats == "yes" || line.calcStats == "true") {
						curobj->actorData.actorBaseFlags.set(RE::ACTOR_BASE_DATA::Flag::kAutoCalcStats);
						logger::debug(FMT_STRING("Enabled kAutoCalcStats for NPC {:08X} {}"), curobj->formID, curobj->fullName);
					} else if (line.calcStats == "no" || line.calcStats == "false") {
						curobj->actorData.actorBaseFlags.reset(RE::ACTOR_BASE_DATA::Flag::kAutoCalcStats);
						logger::debug(FMT_STRING("Disabled kAutoCalcStats for NPC {:08X} {}"), curobj->formID, curobj->fullName);
					}
				}

				if (found && !line.kPCLevelMult.empty() && line.kPCLevelMult != "none") {
					if (line.kPCLevelMult == "yes" || line.kPCLevelMult == "true") {
						curobj->actorData.actorBaseFlags.set(RE::ACTOR_BASE_DATA::Flag::kPCLevelMult);
						logger::debug(FMT_STRING("Enabled kPCLevelMult for NPC {:08X} {}"), curobj->formID, curobj->fullName);
					} else if (line.kPCLevelMult == "no" || line.kPCLevelMult == "false") {
						curobj->actorData.actorBaseFlags.reset(RE::ACTOR_BASE_DATA::Flag::kPCLevelMult);
						logger::debug(FMT_STRING("Disabled kPCLevelMult for NPC {:08X} {}"), curobj->formID, curobj->fullName);
					}
				}

				if (found && !line.kEssential.empty() && line.kEssential != "none") {
					if (line.kEssential == "yes" || line.kEssential == "true") {
						curobj->actorData.actorBaseFlags.set(RE::ACTOR_BASE_DATA::Flag::kEssential);
						logger::debug(FMT_STRING("Enabled kEssential for NPC {:08X} {}"), curobj->formID, curobj->fullName);
					} else if (line.kEssential == "no" || line.kEssential == "false") {
						curobj->actorData.actorBaseFlags.reset(RE::ACTOR_BASE_DATA::Flag::kEssential);
						logger::debug(FMT_STRING("Disabled kEssential for NPC {:08X} {}"), curobj->formID, curobj->fullName);
					}
				}

				if (found && !line.kProtected.empty() && line.kProtected != "none") {
					if (line.kProtected == "yes" || line.kProtected == "true") {
						curobj->actorData.actorBaseFlags.set(RE::ACTOR_BASE_DATA::Flag::kProtected);
						logger::debug(FMT_STRING("Enabled kProtected for NPC {:08X} {}"), curobj->formID, curobj->fullName);
					} else if (line.kProtected == "no" || line.kProtected == "false") {
						curobj->actorData.actorBaseFlags.reset(RE::ACTOR_BASE_DATA::Flag::kProtected);
						logger::debug(FMT_STRING("Disabled kProtected for NPC {:08X} {}"), curobj->formID, curobj->fullName);
					}
				}

				if (found && !line.avifs.empty()) {
					//logger::info("found! patching values");
					//for (const auto& avifstring : line.avifs)
					for (size_t i = 0; i < line.avifs.size(); i++) {
						RE::TESForm* currentform = nullptr;
						std::string string_form = line.avifs[i];
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kAVIF) {
							//logger::info("avif valid!");
							float finalValue = 0;

							if (line.level_min == "none") {
								if (!line.values1.empty() && !line.values2.empty()) {
									unsigned seed = static_cast<unsigned>(std::time(nullptr)) + static_cast<unsigned>(std::clock());
									std::srand(seed);
									//int random_value = std::rand() % 501 + 500;
									finalValue = floor((std::rand() / static_cast<float>(RAND_MAX)) * (line.values2[i] - line.values1[i] + 1) + line.values1[i]);
								}

							} else if (line.level_min != "none" && line.level_max != "none" && line.level_min != line.level_max && line.values1[i] != line.values2[i]) {
								int level_min = std::stoi(line.level_min);  // minimum level
								int level_max = std::stoi(line.level_max);  // maximum level
								if (level_min < level_max) {
									int avif_min = line.values1[i];  // minimum health
									int avif_max = line.values2[i];  // maximum health
									//logger::info(FMT_STRING("lvl min {} level max {} avif min {} avif max {} "), level_min, level_max, line.values1[i], line.values2[i]);
									// Calculate proportional increase
									float health_increase = avif_max - avif_min;
									float level_increase = level_max - level_min;
									float proportional_increase = health_increase / level_increase;

									// Calculate health at level 50
									int target_level = curobj->actorData.level;
									finalValue = avif_min;

									//logger::info(FMT_STRING("lvl min {} level max {} avif min {} avif max {} "), level_min, level_max, line.values1[i], line.values2[i]);

									if (target_level >= level_min && target_level <= level_max) {
										float level_difference = target_level - level_min;
										finalValue = avif_min + (level_difference * proportional_increase);
									} else if (target_level < level_min) {
										finalValue = avif_min;
									} else {
										finalValue = avif_max;
									}
								} else {
									finalValue = line.values1[i];
									logger::info(FMT_STRING("Error: Level Min > Level Max  using default value for av {}"), finalValue);
								}
								//logger::info(FMT_STRING("lvl min {} level max {} avif min {} avif max {} target_level {} healthinc {} levelinc {} propIncrease {} finalValue {}"), level_min, level_max, line.values1[i], line.values2[i], target_level,health_increase, level_increase, proportional_increase, finalValue);

							} else {
								finalValue = line.values1[i];
							}
							
							changeAVIF_NPC(curobj, (RE::ActorValueInfo*)currentform, finalValue);
							logger::debug(FMT_STRING("npc formid: {:08X} {} changed {:08X} {} {}"), curobj->formID, curobj->fullName, ((RE::ActorValueInfo*)currentform)->formID, ((RE::ActorValueInfo*)currentform)->fullName, finalValue);
						}
					}
				}
				if (found && !line.keywordsToAdd.empty()) {
					//logger::info("found! patching values");
					//for (const auto& avifstring : line.avifs)
					for (size_t i = 0; i < line.keywordsToAdd.size(); i++) {
						RE::TESForm* currentform = nullptr;
						std::string string_form = line.keywordsToAdd[i];
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
							curobj->AddKeyword((RE::BGSKeyword*)currentform);
							logger::debug(FMT_STRING("npc formid: {:08X} {} added keyword {:08X} {} "), curobj->formID, curobj->fullName, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
						}
					}
				}

				if (found && !line.keywordsToRemove.empty()) {
					for (size_t i = 0; i < line.keywordsToRemove.size(); i++) {
						RE::TESForm* currentform = nullptr;
						std::string string_form = line.keywordsToRemove[i];
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
							curobj->RemoveKeyword((RE::BGSKeyword*)currentform);
							logger::debug(FMT_STRING("npc formid: {:08X} removed keyword {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
						}
					}
				}

				if (found && !line.factionsToRemove.empty()) {
					for (size_t i = 0; i < line.factionsToRemove.size(); i++) {
						RE::TESForm* currentform = nullptr;
						std::string string_form = line.factionsToRemove[i];
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kFACT) {
							curobj->RemoveFaction((RE::TESFaction*)currentform);
							logger::debug(FMT_STRING("npc formid: {:08X} removed faction {:08X} {} "), curobj->formID, ((RE::TESFaction*)currentform)->formID, ((RE::TESFaction*)currentform)->fullName);
						}
					}
				}

				if (found && !line.factionsToAdd.empty()) {
					//logger::info("found! patching values");
					//for (const auto& avifstring : line.avifs)
					for (size_t i = 0; i < line.factionsToAdd.size(); i++) {
						RE::TESForm* currentform = nullptr;
						std::string string_form = line.factionsToAdd[i];
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kFACT) {
							//logger::info("avif valid!");
							float finalValue = 0;

							if (!line.values1.empty() && !line.values2.empty()) {
								//std::srand(std::time(nullptr));
								finalValue = floor((std::rand() / static_cast<float>(RAND_MAX)) * (line.factionsToAddRank2[i] - line.factionsToAddRank1[i] + 1) + line.factionsToAddRank1[i]);
							}

							curobj->AddFaction((RE::TESFaction*)currentform, finalValue);
							logger::debug(FMT_STRING("npc formid: {:08X} {} added faction {:08X} with rank {}"), curobj->formID, curobj->fullName, ((RE::TESFaction*)currentform)->formID, finalValue);
						}
					}
				}



				if (found && !line.perksToAdd.empty()) {
					//logger::info("found! patching values");
					//for (const auto& avifstring : line.avifs)
					for (size_t i = 0; i < line.perksToAdd.size(); i++) {
						RE::TESForm* currentform = nullptr;
						std::string string_form = line.perksToAdd[i];
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kPERK) {
							curobj->AddPerk((RE::BGSPerk*)currentform, 1);
							logger::info(FMT_STRING("npc formid: {:08X} added perk {:08X} {} "), curobj->formID, ((RE::BGSPerk*)currentform)->formID, ((RE::BGSPerk*)currentform)->fullName);
						}

					}
				}

				if (found && !line.outfitDefault.empty() && line.outfitDefault != "none") {
					RE::TESForm* currentform = nullptr;
					std::string string_form = line.outfitDefault;
					currentform = GetFormFromIdentifier(string_form);
					if (currentform && currentform->formType == RE::ENUM_FORM_ID::kOTFT) {
						curobj->defOutfit = (RE::BGSOutfit*)currentform;
						//curobj->defOutfit->outfitItems.add
						logger::debug(FMT_STRING("npc formid: {:08X} changed outfit default to {:08X} "), curobj->formID, ((RE::BGSOutfit*)currentform)->formID);
					}
				}

				if (found && !line.outfitSleep.empty() && line.outfitSleep != "none") {
					RE::TESForm* currentform = nullptr;
					std::string string_form = line.outfitSleep;
					currentform = GetFormFromIdentifier(string_form);
					if (currentform && currentform->formType == RE::ENUM_FORM_ID::kOTFT) {
						curobj->sleepOutfit = (RE::BGSOutfit*)currentform;
						logger::debug(FMT_STRING("npc formid: {:08X} changed outfit sleep to {:08X} "), curobj->formID, ((RE::BGSOutfit*)currentform)->formID);
					}
				}

				if (found && !line.deathItem.empty() && line.deathItem != "none") {
					RE::TESForm* currentform = nullptr;
					std::string string_form = line.deathItem;
					currentform = GetFormFromIdentifier(string_form);
					if (currentform && currentform->formType == RE::ENUM_FORM_ID::kLVLI) {
						curobj->deathItem = (RE::TESLevItem*)currentform;
						logger::debug(FMT_STRING("npc formid: {:08X} changed deathItem to {:08X} "), curobj->formID, ((RE::TESLevItem*)currentform)->formID);
					} else if (line.deathItem == "null") {
						curobj->deathItem = nullptr;
						logger::debug(FMT_STRING("npc formid: {:08X} changed deathItem to null (none) "), curobj->formID);
					}
				}

				if (found && !line.skin.empty() && line.skin != "none") {
					RE::TESForm* currentform = nullptr;
					std::string string_form = line.skin;
					currentform = GetFormFromIdentifier(string_form);
					if (currentform && currentform->formType == RE::ENUM_FORM_ID::kARMO) {
						curobj->formSkin = (RE::TESObjectARMO*)currentform;
						logger::debug(FMT_STRING("npc formid: {:08X} changed skin to {:08X} "), curobj->formID, ((RE::TESObjectARMO*)currentform)->formID);
					} else if (line.skin == "null") {
						curobj->formSkin = nullptr;
						logger::debug(FMT_STRING("npc formid: {:08X} changed skin to null (none) "), curobj->formID);
					}
				}

				if (found && !line.race.empty() && line.race != "none") {
					RE::TESForm* currentform = nullptr;
					std::string string_form = line.race;
					currentform = GetFormFromIdentifier(string_form);
					if (currentform && currentform->formType == RE::ENUM_FORM_ID::kRACE) {
						curobj->formRace = (RE::TESRace*)currentform ;
						logger::debug(FMT_STRING("npc formid: {:08X} changed race to {:08X} "), curobj->formID, ((RE::TESRace*)currentform)->formID);
					}
				}

				if (found && !line.powerArmorStand.empty() && line.powerArmorStand != "none") {
					RE::TESForm* currentform = nullptr;
					std::string string_form = line.powerArmorStand;
					currentform = GetFormFromIdentifier(string_form);
					if (currentform && currentform->formType == RE::ENUM_FORM_ID::kFURN) {
						curobj->powerArmorFurn = (RE::TESFurniture*)currentform;
						logger::debug(FMT_STRING("npc formid: {:08X} changed power armor stand to {:08X} "), curobj->formID, ((RE::TESFurniture*)currentform)->formID);
					}
					if (line.powerArmorStand == "null") {
						curobj->powerArmorFurn = nullptr;
						logger::debug(FMT_STRING("npc formid: {:08X} changed power armor stand to null (none)"), curobj->formID);
					}
				}

				if (found && !line.Class.empty() && line.Class != "none") {
					RE::TESForm* currentform = nullptr;
					std::string string_form = line.Class;
					currentform = GetFormFromIdentifier(string_form);
					if (currentform && currentform->formType == RE::ENUM_FORM_ID::kCLAS) {
						curobj->cl = (RE::TESClass*)currentform;
						logger::debug(FMT_STRING("npc formid: {:08X} changed class to {:08X} "), curobj->formID, ((RE::TESClass*)currentform)->formID);
					}
				}
				if (found && !line.xpValueOffset.empty() && line.xpValueOffset != "none") {
					try {
						curobj->actorData.xpValueOffset = std::stof(line.xpValueOffset);
						logger::debug(FMT_STRING("npc formid: {:08X} {} changed xpValueOffset to {}"), curobj->formID, curobj->fullName, curobj->actorData.xpValueOffset);
					} catch (const std::invalid_argument& e) {
					}
				}
				if (found && !line.level.empty() && line.level != "none") {
					try {
						curobj->actorData.level = std::stof(line.level);
						logger::debug(FMT_STRING("npc formid: {:08X} {} changed level to {}"), curobj->formID, curobj->fullName, curobj->actorData.level);
					} catch (const std::invalid_argument& e) {
					}
				}
				if (found && !line.calcLevelMin.empty() && line.calcLevelMin != "none") {
					try {
						curobj->actorData.calcLevelMin = std::stof(line.calcLevelMin);
						logger::debug(FMT_STRING("npc formid: {:08X} {} changed calcLevelMin to {}"), curobj->formID, curobj->fullName, curobj->actorData.calcLevelMin);
					} catch (const std::invalid_argument& e) {
					}
				}
				if (found && !line.calcLevelMax.empty() && line.calcLevelMax != "none") {
					try {
						curobj->actorData.calcLevelMax = std::stof(line.calcLevelMax);
						logger::debug(FMT_STRING("npc formid: {:08X} {} changed calcLevelMax to {}"), curobj->formID, curobj->fullName, curobj->actorData.calcLevelMax);
					} catch (const std::invalid_argument& e) {
					}
				}

				if (found && !line.spellsToAdd.empty()) {
					//logger::info(FMT_STRING("Processing Spell list size {}"), line.spellsToAdd.size());
					//for (const auto& avifstring : line.avifs)
					for (size_t i = 0; i < line.spellsToAdd.size(); i++) {
						RE::TESForm* currentform = nullptr;
						std::string string_form = line.spellsToAdd[i];
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kSPEL) {
							curobj->AddSpell(currentform);
							logger::debug(FMT_STRING("npc formid: {:08X} {} added spell {:08X} {} "), curobj->formID, curobj->fullName, ((RE::SpellItem*)currentform)->formID, ((RE::SpellItem*)currentform)->fullName);
						}
					}
				}

				if (found && !line.fullName.empty() && line.fullName != "none") {
					try {
						logger::debug(FMT_STRING("npc formid: {:08X} {} changed fullname to "), curobj->formID, curobj->fullName, line.fullName);
						curobj->fullName = line.fullName;
					} catch (const std::invalid_argument& e) {
					}
				}

				if (found && !line.objectsToAdd.empty()) {
					//logger::info("found! patching values");
					//for (const auto& avifstring : line.avifs)
					for (size_t i = 0; i < line.objectsToAdd.size(); i++) {
						RE::TESForm* currentform = nullptr;
						std::string string_form = line.objectsToAdd[i];
						currentform = GetFormFromIdentifier(string_form);
						if (currentform) {

							RE::TESBoundObject* bo = (RE::TESBoundObject*)currentform;
							if (bo) {
								curobj->AddObject(bo, std::stoi(  line.objectsToAddValue[i]), nullptr  );
								logger::info(FMT_STRING("npc formid: {:08X} added object {:08X} {} "), curobj->formID, ((RE::TESBoundObject*)currentform)->formID, line.objectsToAddValue[i]);
							}
						}
					}
				}

				if (found && !line.objectsToRemove.empty()) {
					//logger::info("found! patching values");
					//for (const auto& avifstring : line.avifs)
					for (size_t i = 0; i < line.objectsToRemove.size(); i++) {
						RE::TESForm* currentform = nullptr;
						std::string string_form = line.objectsToRemove[i];
						currentform = GetFormFromIdentifier(string_form);
						if (currentform) {
							RE::TESBoundObject* bo = (RE::TESBoundObject*)currentform;
							if (bo) {
								curobj->RemoveObject(bo);
								logger::info(FMT_STRING("npc formid: {:08X} removed object {:08X} "), curobj->formID, ((RE::TESBoundObject*)currentform)->formID);
							}
						}
					}
				}

				//if (found && !line.raceAttack.empty() && line.raceAttack != "none") {
				//	RE::TESForm* currentform = nullptr;
				//	std::string string_form = line.raceAttack;
				//	currentform = GetFormFromIdentifier(string_form);
				//	if (currentform && currentform->formType == RE::ENUM_FORM_ID::kLVLI) {
				//		curobj->race = (RE::TESObjectARMO*)currentform;
				//		logger::debug(FMT_STRING("npc formid: {:08X} changed attack race to {:08X} "), curobj->formID, ((RE::TESObjectARMO*)currentform)->formID);
				//	} else {
				//		curobj->formSkin = nullptr;
				//		logger::debug(FMT_STRING("npc formid: {:08X} changed attack race to null (none) "), curobj->formID);
				//	}
				//}
				//
				


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
								std::list<patch_instruction> tokens;
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

	/*void* readConfigNPC()
	{
		logger::debug("Reading config and create forms...");

		char skipChar = '/';
		std::string extension = ".ini";
		DIR* dir;
		struct dirent* ent;
		std::string folder = ".\\Data\\F4se\\Plugins\\RobCo_Patcher\\npc\\";

		if ((dir = opendir(folder.c_str())) != NULL) {
			while ((ent = readdir(dir)) != NULL) {
				if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
					logger::info("*********************************");
					logger::info(FMT_STRING("Config file {} found."), ent->d_name);
					logger::info("*********************************");
				}
				std::string fileName = ent->d_name;
				size_t pos = fileName.find(extension);
				if (pos != std::string::npos) {
					fileName = fileName.substr(0, pos);
					const char* modname = fileName.c_str();

					if ((strstr(modname, ".esp") != nullptr || strstr(modname, ".esl") != nullptr || strstr(modname, ".esm") != nullptr)) {
						if (!IsPluginInstalled(modname)) {
							logger::info(FMT_STRING("{} not found or is not a valid plugin file, skipping config file."), modname);
							continue;
						}
					}

					std::string line;
					std::ifstream infile;
					std::list<patch_instruction_npc> tokens;
					infile.open(folder + ent->d_name);
					while (std::getline(infile, line)) {
						if (line[0] == skipChar) {
							continue;
						}

						if (line.empty()) {
							continue;
						}

						tokens.push_back(create_patch_instruction_npc(line));
					}
					infile.close();
					process_patch_instructions_npc(tokens);
				}
			}
			closedir(dir);
		} else {
			logger::info("Couldn't find npc dir.");
		}

		return 0;
	}*/
}

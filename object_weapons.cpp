#include "object_weapons.h"

namespace WEAPONS
{

	struct patch_instruction create_patch_instructions(const std::string& line)
	{
		patch_instruction l;

		// extract objects
		std::regex objects_regex("filterByWeapons\\s*=([^:]+)", regex::icase);
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
				//logger::info(FMT_STRING("Weapon String: {}"), tempVar);
				if (tempVar != "none") {
					objects.push_back(tempVar);
				}
				++objects_iterator;
			}
			l.object = objects;
		}

		// extract skipFlags
		std::regex skipFlagsExcluded_regex("filterByFlagsExcluded\\s*=([^:]+)", regex::icase);
		std::smatch skipFlagsExcluded_match;
		std::regex_search(line, skipFlagsExcluded_match, skipFlagsExcluded_regex);
		std::vector<std::string> skipFlagsExcluded;
		if (skipFlagsExcluded_match.empty() || skipFlagsExcluded_match[1].str().empty()) {
			//empty
		} else {
			std::string skipFlagsExcluded_str = skipFlagsExcluded_match[1];
			std::regex skipFlagsExcluded_list_regex("[^,]+(\\w+)", regex::icase);
			std::sregex_iterator skipFlagsExcluded_iterator(skipFlagsExcluded_str.begin(), skipFlagsExcluded_str.end(), skipFlagsExcluded_list_regex);
			std::sregex_iterator skipFlagsExcluded_end;
			while (skipFlagsExcluded_iterator != skipFlagsExcluded_end) {
				std::string keyword = (*skipFlagsExcluded_iterator)[0].str();
				keyword.erase(keyword.begin(), std::find_if_not(keyword.begin(), keyword.end(), ::isspace));
				keyword.erase(std::find_if_not(keyword.rbegin(), keyword.rend(), ::isspace).base(), keyword.end());
				if (keyword != "none") {
					skipFlagsExcluded.push_back(keyword);
				}
				++skipFlagsExcluded_iterator;
			}
			l.filterByFlagsExclude = skipFlagsExcluded;
		}

		// extract objectsExcluded
		std::regex objectsExcluded_regex("filterByWeaponsExcluded\\s*=([^:]+)", regex::icase);
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

				// extract filterAmmos
		std::regex filterAmmos_regex("filterByAmmos\\s*=([^:]+)", regex::icase);
		std::smatch filterAmmos_match;
		std::regex_search(line, filterAmmos_match, filterAmmos_regex);
		std::vector<std::string> filterAmmos;
		if (filterAmmos_match.empty() || filterAmmos_match[1].str().empty()) {
			//empty
		} else {
			std::string filterAmmos_str = filterAmmos_match[1];
			std::regex filterAmmos_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator filterAmmos_iterator(filterAmmos_str.begin(), filterAmmos_str.end(), filterAmmos_list_regex);
			std::sregex_iterator filterAmmos_end;
			while (filterAmmos_iterator != filterAmmos_end) {
				std::string tempVar = (*filterAmmos_iterator)[0].str();
				tempVar.erase(tempVar.begin(), std::find_if_not(tempVar.begin(), tempVar.end(), ::isspace));
				tempVar.erase(std::find_if_not(tempVar.rbegin(), tempVar.rend(), ::isspace).base(), tempVar.end());
				//logger::info(FMT_STRING("Race: {}"), race);
				if (tempVar != "none") {
					filterAmmos.push_back(tempVar);
				}
				++filterAmmos_iterator;
			}
			l.filterAmmos = filterAmmos;
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

		// extract attackDamage
		std::regex attackDamage_regex("attackDamage\\s*=([^:]+)", regex::icase);
		std::smatch match;
		std::regex_search(line, match, attackDamage_regex);
		// extract the value after the equals sign
		if (match.empty() || match[1].str().empty()) {
			l.attackDamage = "none";
		} else {
			std::string value = match[1].str();
			value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			l.attackDamage = value;
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

		// extract actionpointcost
		std::regex actionpointcost_regex("attackActionPointCost\\s*=([^:]+)", regex::icase);
		std::smatch actionpointcostmatch;
		std::regex_search(line, actionpointcostmatch, actionpointcost_regex);
		// extract the value after the equals sign
		if (actionpointcostmatch.empty() || actionpointcostmatch[1].str().empty()) {
			l.actionpointcost = "none";
		} else {
			std::string value = actionpointcostmatch[1].str();
			value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			l.actionpointcost = value;
		}

				// extract weaponhittype
		std::regex weaponhittype_regex("weaponHitType\\s*=([^:]+)", regex::icase);
		std::smatch weaponhittypematch;
		std::regex_search(line, weaponhittypematch, weaponhittype_regex);
		// extract the value after the equals sign
		if (weaponhittypematch.empty() || weaponhittypematch[1].str().empty()) {
			l.hittype = "none";
		} else {
			std::string value = weaponhittypematch[1].str();
			value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			l.hittype = value;
		}

		// extract soundLevel
		std::regex soundLevel_regex("soundLevel\\s*=([^:]+)", regex::icase);
		std::smatch soundLevelmatch;
		std::regex_search(line, soundLevelmatch, soundLevel_regex);
		// extract the value after the equals sign
		if (soundLevelmatch.empty() || soundLevelmatch[1].str().empty()) {
			l.soundlevel = "none";
		} else {
			std::string value = soundLevelmatch[1].str();
			value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			l.soundlevel = value;
		}

		// extract bashDamage
		std::regex bashDamage_regex("bashDamage\\s*=([^:]+)", regex::icase);
		std::smatch bashmatch;
		std::regex_search(line, bashmatch, bashDamage_regex);
		// extract the value after the equals sign
		if (bashmatch.empty() || bashmatch[1].str().empty()) {
			l.bashDamage = "none";
		} else {
			std::string bashvalue = bashmatch[1].str();
			bashvalue.erase(std::remove_if(bashvalue.begin(), bashvalue.end(), ::isspace), bashvalue.end());
			l.bashDamage = bashvalue;
		}

				// extract springBackMult
		std::regex springBackMult_regex("recoilDiminishSpringForce\\s*=([^:]+)", regex::icase);
		std::smatch springBackMultmatch;
		std::regex_search(line, springBackMultmatch, springBackMult_regex);
		// extract the value after the equals sign
		if (springBackMultmatch.empty() || springBackMultmatch[1].str().empty()) {
			l.springBackMult = "none";
		} else {
			std::string springBackMultvalue = springBackMultmatch[1].str();
			springBackMultvalue.erase(std::remove_if(springBackMultvalue.begin(), springBackMultvalue.end(), ::isspace), springBackMultvalue.end());
			l.springBackMult = springBackMultvalue;
		}

				// extract accuracyMult
		std::regex accuracyMult_regex("coneIronSightsMultiplier\\s*=([^:]+)", regex::icase);
		std::smatch accuracyMultmatch;
		std::regex_search(line, accuracyMultmatch, accuracyMult_regex);
		// extract the value after the equals sign
		if (accuracyMultmatch.empty() || accuracyMultmatch[1].str().empty()) {
			l.accuracyMult = "none";
		} else {
			std::string accuracyMultvalue = accuracyMultmatch[1].str();
			accuracyMultvalue.erase(std::remove_if(accuracyMultvalue.begin(), accuracyMultvalue.end(), ::isspace), accuracyMultvalue.end());
			l.accuracyMult = accuracyMultvalue;
		}

				// extract recoilPerShotMin
		std::regex recoilPerShotMin_regex("recoilPerShotMin\\s*=([^:]+)", regex::icase);
		std::smatch recoilPerShotMinmatch;
		std::regex_search(line, recoilPerShotMinmatch, recoilPerShotMin_regex);
		// extract the value after the equals sign
		if (recoilPerShotMinmatch.empty() || recoilPerShotMinmatch[1].str().empty()) {
			l.recoilPerShotMin = "none";
		} else {
			std::string recoilPerShotMinvalue = recoilPerShotMinmatch[1].str();
			recoilPerShotMinvalue.erase(std::remove_if(recoilPerShotMinvalue.begin(), recoilPerShotMinvalue.end(), ::isspace), recoilPerShotMinvalue.end());
			l.recoilPerShotMin = recoilPerShotMinvalue;
		}

				// extract recoilPerShotMax
		std::regex recoilPerShotMax_regex("recoilPerShotMax\\s*=([^:]+)", regex::icase);
		std::smatch recoilPerShotMaxmatch;
		std::regex_search(line, recoilPerShotMaxmatch, recoilPerShotMax_regex);
		// extract the value after the equals sign
		if (recoilPerShotMaxmatch.empty() || recoilPerShotMaxmatch[1].str().empty()) {
			l.recoilPerShotMax = "none";
		} else {
			std::string recoilPerShotMaxvalue = recoilPerShotMaxmatch[1].str();
			recoilPerShotMaxvalue.erase(std::remove_if(recoilPerShotMaxvalue.begin(), recoilPerShotMaxvalue.end(), ::isspace), recoilPerShotMaxvalue.end());
			l.recoilPerShotMax = recoilPerShotMaxvalue;
		}

		// extract out of range mult
		std::regex oor_regex("outOfRangeDamageMult\\s*=([^:]+)", regex::icase);
		std::smatch oormatch;
		std::regex_search(line, oormatch, oor_regex);
		// extract the value after the equals sign
		if (oormatch.empty() || oormatch[1].str().empty()) {
			l.outOfRangeDamageMult = "none";
		} else {
			std::string oorvalue = oormatch[1].str();
			oorvalue.erase(std::remove_if(oorvalue.begin(), oorvalue.end(), ::isspace), oorvalue.end());
			l.outOfRangeDamageMult = oorvalue;
		}

		// extract weaponlist
		std::regex list_regex("filterByHasAmmoFromWeaponList\\s*=([^:]+)", regex::icase);
		std::smatch listmatch;
		std::regex_search(line, listmatch, list_regex);
		// extract the value after the equals sign
		if (listmatch.empty() || listmatch[1].str().empty()) {
			l.weaponList = "none";
		} else {
			std::string listvalue = listmatch[1].str();
			listvalue.erase(std::remove_if(listvalue.begin(), listvalue.end(), ::isspace), listvalue.end());
			l.weaponList = listvalue;
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

		// extract attachParentSlotKeywordsToAdd
		std::regex attachParentSlotKeywordsToAdd_regex("attachParentSlotKeywordsToAdd\\s*=([^:]+)", regex::icase);
		std::smatch attachParentSlotKeywordsToAdd_match;
		std::regex_search(line, attachParentSlotKeywordsToAdd_match, attachParentSlotKeywordsToAdd_regex);
		std::vector<std::string> attachParentSlotKeywordsToAdd;
		if (attachParentSlotKeywordsToAdd_match.empty() || attachParentSlotKeywordsToAdd_match[1].str().empty()) {
			// ammos_match[1] is null
		} else {
			std::string attachParentSlotKeywordsToAdd_str = attachParentSlotKeywordsToAdd_match[1];
			std::regex attachParentSlotKeywordsToAdd_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator attachParentSlotKeywordsToAdd_iterator(attachParentSlotKeywordsToAdd_str.begin(), attachParentSlotKeywordsToAdd_str.end(), attachParentSlotKeywordsToAdd_list_regex);
			std::sregex_iterator attachParentSlotKeywordsToAdd_end;
			while (attachParentSlotKeywordsToAdd_iterator != attachParentSlotKeywordsToAdd_end) {
				std::string keywordToAdd = (*attachParentSlotKeywordsToAdd_iterator)[0].str();
				keywordToAdd.erase(keywordToAdd.begin(), std::find_if_not(keywordToAdd.begin(), keywordToAdd.end(), ::isspace));
				keywordToAdd.erase(std::find_if_not(keywordToAdd.rbegin(), keywordToAdd.rend(), ::isspace).base(), keywordToAdd.end());
				if (keywordToAdd != "none") {
					//logger::info(FMT_STRING("attachParentSlotKeywordsToAdd: {}"), keywordToAdd);
					attachParentSlotKeywordsToAdd.push_back(keywordToAdd);
				}
				++attachParentSlotKeywordsToAdd_iterator;
			}
			l.attachParentSlotKeywordsToAdd = attachParentSlotKeywordsToAdd;
		}

			// extract attachParentSlotKeywordsToRemove
		std::regex attachParentSlotKeywordsToRemove_regex("attachParentSlotKeywordsToRemove\\s*=([^:]+)", regex::icase);
		std::smatch attachParentSlotKeywordsToRemove_match;
		std::regex_search(line, attachParentSlotKeywordsToRemove_match, attachParentSlotKeywordsToRemove_regex);
		std::vector<std::string> attachParentSlotKeywordsToRemove;
		if (attachParentSlotKeywordsToRemove_match.empty() || attachParentSlotKeywordsToRemove_match[1].str().empty()) {
			// ammos_match[1] is null
		} else {
			std::string attachParentSlotKeywordsToRemove_str = attachParentSlotKeywordsToRemove_match[1];
			std::regex attachParentSlotKeywordsToRemove_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator attachParentSlotKeywordsToRemove_iterator(attachParentSlotKeywordsToRemove_str.begin(), attachParentSlotKeywordsToRemove_str.end(), attachParentSlotKeywordsToRemove_list_regex);
			std::sregex_iterator attachParentSlotKeywordsToRemove_end;
			while (attachParentSlotKeywordsToRemove_iterator != attachParentSlotKeywordsToRemove_end) {
				std::string keywordToRemove = (*attachParentSlotKeywordsToRemove_iterator)[0].str();
				keywordToRemove.erase(keywordToRemove.begin(), std::find_if_not(keywordToRemove.begin(), keywordToRemove.end(), ::isspace));
				keywordToRemove.erase(std::find_if_not(keywordToRemove.rbegin(), keywordToRemove.rend(), ::isspace).base(), keywordToRemove.end());
				if (keywordToRemove != "none") {
					//logger::info(FMT_STRING("attachParentSlotKeywordsToRemove: {}"), keywordToRemove);
					attachParentSlotKeywordsToRemove.push_back(keywordToRemove);
				}
				++attachParentSlotKeywordsToRemove_iterator;
			}
			l.attachParentSlotKeywordsToRemove = attachParentSlotKeywordsToRemove;
		}

		// extract ammos
		std::regex ammos_regex("setNewAmmo\\s*=([^:]+)", regex::icase);
		std::smatch ammos_match;
		std::regex_search(line, ammos_match, ammos_regex);
		std::vector<std::string> ammos;
		if (ammos_match.empty() || ammos_match[1].str().empty()) {
			//empty
		} else {
			std::string ammos_str = ammos_match[1];
			std::regex ammos_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator ammos_iterator(ammos_str.begin(), ammos_str.end(), ammos_list_regex);
			std::sregex_iterator ammos_end;
			while (ammos_iterator != ammos_end) {
				std::string ammo = (*ammos_iterator)[0].str();
				ammo.erase(ammo.begin(), std::find_if_not(ammo.begin(), ammo.end(), ::isspace));
				ammo.erase(std::find_if_not(ammo.rbegin(), ammo.rend(), ::isspace).base(), ammo.end());
				//logger::info(FMT_STRING("Ammo String: {}"), ammo);
				if (ammo != "none") {
					ammos.push_back(ammo);
				}
				++ammos_iterator;
			}
			l.ammo = ammos;
		}

		// extract ammosList
		std::regex ammosList_regex("setNewAmmoList\\s*=([^:]+)", regex::icase);
		std::smatch ammosList_match;
		std::regex_search(line, ammosList_match, ammosList_regex);
		std::vector<std::string> ammosList;
		if (ammosList_match.empty() || ammosList_match[1].str().empty()) {
			// ammos_match[1] is null
		} else {
			std::string ammosList_str = ammosList_match[1];
			std::regex ammosList_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator ammosList_iterator(ammosList_str.begin(), ammosList_str.end(), ammosList_list_regex);
			std::sregex_iterator ammosList_end;
			while (ammosList_iterator != ammosList_end) {
				std::string ammoList = (*ammosList_iterator)[0].str();
				ammoList.erase(ammoList.begin(), std::find_if_not(ammoList.begin(), ammoList.end(), ::isspace));
				ammoList.erase(std::find_if_not(ammoList.rbegin(), ammoList.rend(), ::isspace).base(), ammoList.end());
				//logger::info(FMT_STRING("Race: {}"), race);
				if (ammoList != "none") {
					ammosList.push_back(ammoList);
				}
				++ammosList_iterator;
			}
			l.ammoList = ammosList;
		}

		// extract aimModels
		std::regex aimModels_regex("aimModel\\s*=([^:]+)", regex::icase);
		std::smatch aimModels_match;
		std::regex_search(line, aimModels_match, aimModels_regex);
		std::vector<std::string> aimModels;
		if (aimModels_match.empty() || aimModels_match[1].str().empty()) {
			//empty
		} else {
			std::string aimModels_str = aimModels_match[1];
			std::regex aimModels_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator aimModels_iterator(aimModels_str.begin(), aimModels_str.end(), aimModels_list_regex);
			std::sregex_iterator aimModels_end;
			while (aimModels_iterator != aimModels_end) {
				std::string aimModel = (*aimModels_iterator)[0].str();
				aimModel.erase(aimModel.begin(), std::find_if_not(aimModel.begin(), aimModel.end(), ::isspace));
				aimModel.erase(std::find_if_not(aimModel.rbegin(), aimModel.rend(), ::isspace).base(), aimModel.end());
				//logger::info(FMT_STRING("Race: {}"), race);
				if (aimModel != "none") {
					aimModels.push_back(aimModel);
				}
				++aimModels_iterator;
			}
			l.aimModel = aimModels;
		}

		// extract overrideProjectile
		std::regex overrideProjectile_regex("overrideProjectile\\s*=([^:]+)", regex::icase);
		std::smatch overrideProjectilematch;
		std::regex_search(line, overrideProjectilematch, overrideProjectile_regex);
		// extract the value after the equals sign
		if (overrideProjectilematch.empty() || overrideProjectilematch[1].str().empty()) {
			l.overrideProjectile = "none";
		} else {
			std::string keyword = overrideProjectilematch[1].str();
			keyword.erase(keyword.begin(), std::find_if_not(keyword.begin(), keyword.end(), ::isspace));
			keyword.erase(std::find_if_not(keyword.rbegin(), keyword.rend(), ::isspace).base(), keyword.end());
			l.overrideProjectile = keyword;
		}

		// extract DamageTypes
		std::regex DamageTypes_regex("changeDamageTypes\\s*=([^:]+)", regex::icase);
		std::smatch DamageTypes_match;
		std::regex_search(line, DamageTypes_match, DamageTypes_regex);
		std::vector<std::string> DamageTypes_before_eq;
		std::vector<float> DamageTypes_min_values;
		std::vector<float> DamageTypes_max_values;
		if (DamageTypes_match.empty() || DamageTypes_match[1].str().empty()) {
			//empty
		} else {
			std::string DamageTypes_str = DamageTypes_match[1];
			std::regex DamageTypes_list_regex("([^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8})\\s*=\\s*([\\d.]+)(?:\\s*~\\s*([\\d.]+))?", regex::icase);
			std::sregex_iterator DamageTypes_iterator(DamageTypes_str.begin(), DamageTypes_str.end(), DamageTypes_list_regex);
			std::sregex_iterator DamageTypes_end;
			while (DamageTypes_iterator != DamageTypes_end) {
				std::string avif = (*DamageTypes_iterator)[1].str();
				avif.erase(avif.begin(), std::find_if_not(avif.begin(), avif.end(), ::isspace));
				avif.erase(std::find_if_not(avif.rbegin(), avif.rend(), ::isspace).base(), avif.end());

				if (avif == "none") {
					break;
				}

				DamageTypes_before_eq.push_back(avif);
				DamageTypes_min_values.push_back(std::stof((*DamageTypes_iterator)[2]));
				if ((*DamageTypes_iterator)[3] != "") {
					DamageTypes_max_values.push_back(std::stof((*DamageTypes_iterator)[3]));
				} else {
					DamageTypes_max_values.push_back(std::stof((*DamageTypes_iterator)[2]));
				}
				std::string val1 = ((*DamageTypes_iterator)[2]);
				std::string val2 = ((*DamageTypes_iterator)[3] != "") ? ((*DamageTypes_iterator)[3]) : ((*DamageTypes_iterator)[2]);
				//logger::info(FMT_STRING("avif: {}"), avif);
				//logger::info(FMT_STRING("value1: {}"), val1);
				//logger::info(FMT_STRING("value2: {}"), val2);
				++DamageTypes_iterator;
			}
			l.damageTypes = DamageTypes_before_eq;
			l.values1 = DamageTypes_min_values;
			l.values2 = DamageTypes_max_values;
		}
		
		// extract DamageTypesChangeNew
		std::regex DamageTypesChangeNew_regex("damageTypesToChange\\s*=([^:]+)", regex::icase);
		std::smatch DamageTypesChangeNew_match;
		std::regex_search(line, DamageTypesChangeNew_match, DamageTypesChangeNew_regex);
		std::vector<std::string> DamageTypesChangeNew_before_eq;
		std::vector<float> DamageTypesNew_min_values;
		std::vector<float> DamageTypesNew_max_values;
		if (DamageTypesChangeNew_match.empty() || DamageTypesChangeNew_match[1].str().empty()) {
			//empty
		} else {
				std::string DamageTypes_str = DamageTypesChangeNew_match[1];
			std::regex DamageTypes_list_regex("([^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8})\\s*=\\s*([\\d.]+)(?:\\s*~\\s*([\\d.]+))?", regex::icase);
			std::sregex_iterator DamageTypes_iterator(DamageTypes_str.begin(), DamageTypes_str.end(), DamageTypes_list_regex);
			std::sregex_iterator DamageTypes_end;
			while (DamageTypes_iterator != DamageTypes_end) {
				std::string avif = (*DamageTypes_iterator)[1].str();
				avif.erase(avif.begin(), std::find_if_not(avif.begin(), avif.end(), ::isspace));
				avif.erase(std::find_if_not(avif.rbegin(), avif.rend(), ::isspace).base(), avif.end());

				if (avif == "none") {
					break;
				}

				DamageTypesChangeNew_before_eq.push_back(avif);
				DamageTypesNew_min_values.push_back(std::stof((*DamageTypes_iterator)[2]));
				if ((*DamageTypes_iterator)[3] != "") {
					DamageTypesNew_max_values.push_back(std::stof((*DamageTypes_iterator)[3]));
				} else {
					DamageTypesNew_max_values.push_back(std::stof((*DamageTypes_iterator)[2]));
				}
				std::string val1 = ((*DamageTypes_iterator)[2]);
				std::string val2 = ((*DamageTypes_iterator)[3] != "") ? ((*DamageTypes_iterator)[3]) : ((*DamageTypes_iterator)[2]);
				//logger::info(FMT_STRING("avif: {}"), avif);
				//logger::info(FMT_STRING("value1: {}"), val1);
				//logger::info(FMT_STRING("value2: {}"), val2);
				++DamageTypes_iterator;
			}
			l.damageTypes = DamageTypesChangeNew_before_eq;
			l.values1 = DamageTypesNew_min_values;
			l.values2 = DamageTypesNew_max_values;
		}

		// extract damageTypesToRemove
		std::regex damageTypesToRemove_regex("damageTypesToRemove\\s*=([^:]+)", regex::icase);
		std::smatch damageTypesToRemove_match;
		std::regex_search(line, damageTypesToRemove_match, damageTypesToRemove_regex);
		std::vector<std::string> damageTypesToRemove;
		if (damageTypesToRemove_match.empty() || damageTypesToRemove_match[1].str().empty()) {
			//empty
		} else {
			std::string damageTypesToRemove_str = damageTypesToRemove_match[1];
			std::regex damageTypesToRemove_list_regex("[^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8}", regex::icase);
			std::sregex_iterator damageTypesToRemove_iterator(damageTypesToRemove_str.begin(), damageTypesToRemove_str.end(), damageTypesToRemove_list_regex);
			std::sregex_iterator damageTypesToRemove_end;
			while (damageTypesToRemove_iterator != damageTypesToRemove_end) {
				std::string keywordToRemove = (*damageTypesToRemove_iterator)[0].str();
				keywordToRemove.erase(keywordToRemove.begin(), std::find_if_not(keywordToRemove.begin(), keywordToRemove.end(), ::isspace));
				keywordToRemove.erase(std::find_if_not(keywordToRemove.rbegin(), keywordToRemove.rend(), ::isspace).base(), keywordToRemove.end());
				if (keywordToRemove != "none") {
					//logger::info(FMT_STRING("damageTypesToRemove: {}"), keywordToRemove);
					damageTypesToRemove.push_back(keywordToRemove);
				}
				++damageTypesToRemove_iterator;
			}
			l.damageTypesToRemove = damageTypesToRemove;
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

		logger::debug(FMT_STRING("weapon: {}  keywords: {}  ammo: {} keywordsToAdd: {} aimModel {}"), l.object.size(), l.keywords.size(), l.ammo.size(), l.keywordsToAdd.size(), l.aimModel.size());
		//logger::info("returning patch instructions");
		return l;
	}


	void process_patch_instructions(const std::list<patch_instruction>& tokens)
	{
		logger::debug("processing patch instructions");
		const auto dataHandler = RE::TESDataHandler::GetSingleton();
		RE::BSTArray<RE::TESObjectWEAP*> RaceArray = dataHandler->GetFormArray<RE::TESObjectWEAP>();

		for (const auto& line : tokens) {
			
			if (!line.object.empty()) {
				//logger::info("npc not empty");
				for (const auto& npcstring : line.object) {
					RE::TESForm* currentform = nullptr;
					RE::TESObjectWEAP* curobj = nullptr;

					std::string string_form = npcstring;
					currentform = GetFormFromIdentifier(string_form);
					if (currentform && currentform->formType == RE::ENUM_FORM_ID::kWEAP) {
						curobj = (RE::TESObjectWEAP*)currentform;
						patch(line, curobj);
					}
				}
			}

			if (!line.object.empty() && line.filterAmmos.empty() && line.keywords.empty() && line.keywordsOr.empty() && (line.weaponList.empty() || line.weaponList == "none")) {
				//logger::info("continue");
				continue;
			}


			for (const auto& curobj : RaceArray) {
				//logger::info("processing npc");
				bool found = false;
				bool keywordAnd = false;
				bool keywordOr = false;

				//if (!line.object.empty()) {
				//	//logger::info("npc not empty");
				//	for (const auto& npcstring : line.object) {
				//		RE::TESForm* currentform = nullptr;
				//		RE::TESObjectWEAP* npc = nullptr;

				//		std::string string_form = npcstring;
				//		currentform = GetFormFromIdentifier(string_form);
				//		if (currentform && currentform->formType == RE::ENUM_FORM_ID::kWEAP) {
				//			npc = (RE::TESObjectWEAP*)currentform;

				//			if (curobj->formID == npc->formID) {
				//				found = true;
				//				//logger::info(FMT_STRING("Weapon found!  {:08X} {}"), curobj->formID, curobj->fullName);
				//				break;
				//			}
				//		}
				//	}
				//}
				
				if (!line.filterAmmos.empty()) {
					//logger::info("npc not empty");
					for (const auto& npcstring : line.filterAmmos) {
						RE::TESForm* currentform = nullptr;
						RE::TESAmmo* npc = nullptr;

						std::string string_form = npcstring;
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kAMMO) {
							npc = (RE::TESAmmo*)currentform;

							if (curobj->weaponData.ammo && curobj->weaponData.ammo->formID == npc->formID) {
								found = true;
								break;
							}
						}
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

				if (!found && !line.weaponList.empty() && line.weaponList != "none" && curobj->weaponData.ammo) {
					//logger::info("keywords not empty");

					RE::TESForm* currentform = nullptr;
					RE::BGSKeyword* keyword = nullptr;

					RE::TESAmmo* curammo = curobj->weaponData.ammo;

					int ammoindex = -1;
					if (line.weaponList == "pistol") {
						//logger::debug(FMT_STRING("Weapon after ammoindex pistol {:08X} {}"), curnpc->formID, curnpc->fullName.c_str());
						if (ammoindex == -1) {
							ammoindex = findPositionInArray(listPistol, curammo);
							//logger::debug(FMT_STRING("Weapon ammoindex pistol {:08X} {}  {}"), curnpc->formID, curnpc->fullName.c_str() , ammoindex);
							if (ammoindex >= 0) {
								found = true;
								logger::debug(FMT_STRING("Weapon {:08X} {} has ammo {:08X} {} from list pistol index: {}"), curobj->formID, curobj->fullName.c_str(), curammo->formID, curammo->fullName.c_str(), ammoindex);
							}
						}
					} else if (line.weaponList == "rifle") {
						if (ammoindex == -1) {
							ammoindex = findPositionInArray(listRifle, curammo);
							if (ammoindex >= 0) {
								found = true;
								logger::debug(FMT_STRING("Weapon {:08X} {} has ammo {:08X} {} from list rifle index: {}"), curobj->formID, curobj->fullName.c_str(), curammo->formID, curammo->fullName.c_str(), ammoindex);
							}
						}
					}
				}

				if (!found && line.object.empty() && line.filterAmmos.empty() && line.keywords.empty() && line.keywordsOr.empty() && !line.weaponList.empty() && line.weaponList == "none") {
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

				if (!line.objectExcluded.empty()) {
					//logger::info("npc not empty");
					for (const auto& npcstring : line.objectExcluded) {
						RE::TESForm* currentform = nullptr;
						RE::TESObjectWEAP* npc = nullptr;

						std::string string_form = npcstring;
						currentform = GetFormFromIdentifier(string_form);
						if (currentform && currentform->formType == RE::ENUM_FORM_ID::kWEAP) {
							npc = (RE::TESObjectWEAP*)currentform;

							if (curobj->formID == npc->formID) {
								found = false;
								logger::info("Weapon Excluded.");
								break;
							}
						}
					}
				}

				if (!line.filterByFlagsExclude.empty()) {
					for (const auto& flag : line.filterByFlagsExclude) {
						//logger::debug(FMT_STRING("weapon formid: {:08X} {} filterByFlagsExclude"), curobj->formID, curobj->fullName);
						if (toLowerCase(flag) == "notplayable" && curobj->weaponData.flags & RE::WEAPONDATAFLAGS::kNotPlayable) {
							//logger::debug(FMT_STRING("weapon formid: {:08X} {} filterByFlagsExclude nonplayable set to false"), curobj->formID, curobj->fullName);
							found = false;
						} else if (toLowerCase(flag) == "cantdrop" && curobj->weaponData.flags & RE::WEAPONDATAFLAGS::kCantDrop) {
							//logger::debug(FMT_STRING("weapon formid: {:08X} {} filterByFlagsExclude cantdrop false"), curobj->formID, curobj->fullName);
							found = false;
						} else if (toLowerCase(flag) == "embeddedweapon" && curobj->weaponData.flags & RE::WEAPONDATAFLAGS::kEmbeddedWeapon) {
							//logger::debug(FMT_STRING("weapon formid: {:08X} {} filterByFlagsExclude cantdrop false"), curobj->formID, curobj->fullName);
							found = false;
						} else if (toLowerCase(flag) == "chargingattack" && curobj->weaponData.flags & RE::WEAPONDATAFLAGS::kChargingAttack) {
							//logger::debug(FMT_STRING("weapon formid: {:08X} {} filterByFlagsExclude cantdrop false"), curobj->formID, curobj->fullName);
							found = false;
						} else if (toLowerCase(flag) == "criteffectondeath" && curobj->weaponData.flags & RE::WEAPONDATAFLAGS::kCritEffectOnDeath) {
							//logger::debug(FMT_STRING("weapon formid: {:08X} {} filterByFlagsExclude cantdrop false"), curobj->formID, curobj->fullName);
							found = false;
						} else if (toLowerCase(flag) == "boltaction" && curobj->weaponData.flags & RE::WEAPONDATAFLAGS::kBoltAction) {
							//logger::debug(FMT_STRING("weapon formid: {:08X} {} filterByFlagsExclude cantdrop false"), curobj->formID, curobj->fullName);
							found = false;
						} else if (toLowerCase(flag) == "automatic" && curobj->weaponData.flags & RE::WEAPONDATAFLAGS::kAutomatic) {
							//logger::debug(FMT_STRING("weapon formid: {:08X} {} filterByFlagsExclude cantdrop false"), curobj->formID, curobj->fullName);
							found = false;
						} else if (toLowerCase(flag) == "secondaryweapon" && curobj->weaponData.flags & RE::WEAPONDATAFLAGS::kSecondaryWeapon) {
							//logger::debug(FMT_STRING("weapon formid: {:08X} {} filterByFlagsExclude cantdrop false"), curobj->formID, curobj->fullName);
							found = false;
						} else if (toLowerCase(flag) == "chargingreload" && curobj->weaponData.flags & RE::WEAPONDATAFLAGS::kChargingReload) {
							//logger::debug(FMT_STRING("weapon formid: {:08X} {} filterByFlagsExclude cantdrop false"), curobj->formID, curobj->fullName);
							found = false;
						} else if (toLowerCase(flag) == "holdinputtopower" && curobj->weaponData.flags & RE::WEAPONDATAFLAGS::kHoldInputToPower) {
							//logger::debug(FMT_STRING("weapon formid: {:08X} {} filterByFlagsExclude cantdrop false"), curobj->formID, curobj->fullName);
							found = false;
						}
					}
				
				}

				if (found) {
					patch(line,curobj);
				}

				//if (found && !line.attackDamage.empty() && line.attackDamage != "none") {
				//	try {
				//		curobj->weaponData.attackDamage = std::stof(line.attackDamage);
				//		logger::debug(FMT_STRING("weapon formid: {:08X} {} changed damage {}"), curobj->formID, curobj->fullName, curobj->weaponData.attackDamage);
				//	} catch (const std::invalid_argument& e) {
				//	}
				//}
				//if (found && !line.weight.empty() && line.weight != "none") {
				//	try {
				//		curobj->weaponData.weight = std::stof(line.weight);
				//		logger::debug(FMT_STRING("weapon formid: {:08X} {} changed weight {}"), curobj->formID, curobj->fullName, curobj->weaponData.weight);
				//	} catch (const std::invalid_argument& e) {
				//	}
				//}
				//if (found && !line.capsvalue.empty() && line.capsvalue != "none") {
				//	try {
				//		curobj->weaponData.value = std::stof(line.capsvalue);
				//		logger::debug(FMT_STRING("weapon formid: {:08X} {} changed value {}"), curobj->formID, curobj->fullName, curobj->weaponData.value);
				//	} catch (const std::invalid_argument& e) {
				//	}
				//}
				//if (found && !line.actionpointcost.empty() && line.actionpointcost != "none") {
				//	try {
				//		curobj->weaponData.attackActionPointCost = std::stof(line.actionpointcost);
				//		logger::debug(FMT_STRING("weapon formid: {:08X} {} changed attack actionpoint cost {}"), curobj->formID, curobj->fullName, curobj->weaponData.attackActionPointCost);
				//	} catch (const std::invalid_argument& e) {
				//	}
				//}

				//if (found && !line.hittype.empty() && line.hittype != "none") {
				//	try {
				//		std::string hittypeLower = line.hittype;
				//		std::transform(hittypeLower.begin(), hittypeLower.end(), hittypeLower.begin(), [](unsigned char c) {
				//			return std::tolower(c);  // convert to lowercase
				//		});

				//		if (hittypeLower == "normal") {
				//			curobj->weaponData.hitBehavior = RE::WEAPONHITBEHAVIOR::kNormal;
				//			logger::debug(FMT_STRING("weapon formid: {:08X} {} changed hit behavior to normal"), curobj->formID, curobj->fullName);
				//		} else if (hittypeLower == "dismemberonly" || hittypeLower == "dismember") {
				//			curobj->weaponData.hitBehavior = RE::WEAPONHITBEHAVIOR::kDismemberOnly;
				//			logger::debug(FMT_STRING("weapon formid: {:08X} {} changed hit behavior to dismember only"), curobj->formID, curobj->fullName);
				//		} else if (hittypeLower == "explodeOnly" || hittypeLower == "explode") {
				//			curobj->weaponData.hitBehavior = RE::WEAPONHITBEHAVIOR::kExplodeOnly;
				//			logger::debug(FMT_STRING("weapon formid: {:08X} {} changed hit behavior to explode only"), curobj->formID, curobj->fullName);
				//		} else if (hittypeLower == "nodismemberorexplode" || hittypeLower == "no") {
				//			curobj->weaponData.hitBehavior = RE::WEAPONHITBEHAVIOR::kNoDismemberOrExplode;
				//			logger::debug(FMT_STRING("weapon formid: {:08X} {} changed hit behavior to no dismember or explode"), curobj->formID, curobj->fullName);
				//		}

				//		
				//	} catch (const std::invalid_argument& e) {
				//	}
				//}

				//if (found && !line.soundlevel.empty() && line.soundlevel != "none") {
				//	try {
				//		std::string hittypeLower = line.soundlevel;
				//		std::transform(hittypeLower.begin(), hittypeLower.end(), hittypeLower.begin(), [](unsigned char c) {
				//			return std::tolower(c);  // convert to lowercase
				//		});

				//		if (hittypeLower == "loud") {
				//			curobj->weaponData.soundLevel = RE::SOUND_LEVEL::kLoud;
				//			logger::debug(FMT_STRING("weapon formid: {:08X} {} changed sound level to loud"), curobj->formID, curobj->fullName);
				//		} else if (hittypeLower == "normal") {
				//			curobj->weaponData.soundLevel = RE::SOUND_LEVEL::kNormal;
				//			logger::debug(FMT_STRING("weapon formid: {:08X} {} changed sound level to normal"), curobj->formID, curobj->fullName);
				//		} else if (hittypeLower == "silent") {
				//			curobj->weaponData.soundLevel = RE::SOUND_LEVEL::kSilent;
				//			logger::debug(FMT_STRING("weapon formid: {:08X} {} changed sound level to silent"), curobj->formID, curobj->fullName);
				//		} else if (hittypeLower == "veryload") {
				//			curobj->weaponData.soundLevel = RE::SOUND_LEVEL::kVeryLoud;
				//			logger::debug(FMT_STRING("weapon formid: {:08X} {} changed sound level to very load"), curobj->formID, curobj->fullName);
				//		} else if (hittypeLower == "quiet") {
				//			curobj->weaponData.soundLevel = RE::SOUND_LEVEL::kQuiet;
				//			logger::debug(FMT_STRING("weapon formid: {:08X} {} changed sound level to quiet"), curobj->formID, curobj->fullName);
				//		}

				//	} catch (const std::invalid_argument& e) {
				//	}
				//}

				//if (found && !line.bashDamage.empty() && line.bashDamage != "none") {
				//	try {
				//		curobj->weaponData.secondaryDamage = std::stof(line.bashDamage);
				//		logger::debug(FMT_STRING("weapon formid: {:08X} {} changed damage {}"), curobj->formID, curobj->fullName, curobj->weaponData.secondaryDamage);
				//	} catch (const std::invalid_argument& e) {
				//	}
				//}
				//if (found && !line.outOfRangeDamageMult.empty() && line.outOfRangeDamageMult != "none") {
				//	try {
				//		curobj->weaponData.outOfRangeDamageMult = std::stof(line.outOfRangeDamageMult);
				//		logger::debug(FMT_STRING("weapon formid: {:08X} {} changed outOfRangeDamageMult {}"), curobj->formID, curobj->fullName, curobj->weaponData.outOfRangeDamageMult);
				//	} catch (const std::invalid_argument& e) {
				//	}
				//}
				//if (found && !line.attachParentSlotKeywordsToAdd.empty()) {
				//	//logger::info("found! patching values");
				//	//for (const auto& avifstring : line.avifs)
				//	for (size_t i = 0; i < line.attachParentSlotKeywordsToAdd.size(); i++) {
				//		RE::TESForm* currentform = nullptr;
				//		std::string string_form = line.attachParentSlotKeywordsToAdd[i];
				//		currentform = GetFormFromIdentifier(string_form);
				//		if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
				//			if (!curobj->attachParents.HasKeyword((RE::BGSKeyword*)currentform)) {
				//				curobj->attachParents.AddKeyword((RE::BGSKeyword*)currentform);
				//				logger::debug(FMT_STRING("weapon formid: {:08X} {} added attach parent slot keyword {:08X} {} "), curobj->formID, curobj->fullName, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
				//			}
				//		}
				//	}
				//}
				//if (found && !line.attachParentSlotKeywordsToRemove.empty()) {
				//	for (size_t i = 0; i < line.attachParentSlotKeywordsToRemove.size(); i++) {
				//		RE::TESForm* currentform = nullptr;
				//		std::string string_form = line.attachParentSlotKeywordsToRemove[i];
				//		currentform = GetFormFromIdentifier(string_form);
				//		if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
				//			if (!curobj->attachParents.HasKeyword((RE::BGSKeyword*)currentform)) {
				//				curobj->attachParents.RemoveKeyword((RE::BGSKeyword*)currentform);

				//				logger::debug(FMT_STRING("armor formid: {:08X} removed attach parent slot keyword {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
				//			}
				//		}
				//	}
				//}
				//if (found && !line.keywordsToAdd.empty()) {
				//	for (size_t i = 0; i < line.keywordsToAdd.size(); i++) {
				//		RE::TESForm* currentform = nullptr;
				//		std::string string_form = line.keywordsToAdd[i];
				//		currentform = GetFormFromIdentifier(string_form);
				//		if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
				//			curobj->AddKeyword((RE::BGSKeyword*)currentform);
				//			logger::debug(FMT_STRING("weapon formid: {:08X} {} added keyword {:08X} {} "), curobj->formID, curobj->fullName, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
				//		}
				//	}
				//}

				//if (found && !line.keywordsToRemove.empty()) {
				//	for (size_t i = 0; i < line.keywordsToRemove.size(); i++) {
				//		RE::TESForm* currentform = nullptr;
				//		std::string string_form = line.keywordsToRemove[i];
				//		currentform = GetFormFromIdentifier(string_form);
				//		if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
				//			curobj->RemoveKeyword((RE::BGSKeyword*)currentform);
				//			logger::debug(FMT_STRING("weapon formid: {:08X} removed keyword {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
				//		}
				//	}
				//}
				//
				//if (found && !line.ammo.empty()) {
				//	//logger::info(FMT_STRING("found in ammo {}"), found);
				//	for (size_t i = 0; i < line.ammo.size(); i++) {
				//		//logger::info(FMT_STRING("found in ammo {} {}"), line.ammo.size(), line.ammo[i]);
				//		RE::TESForm* currentform = nullptr;
				//		std::string string_form = line.ammo[i];
				//		currentform = GetFormFromIdentifier(string_form);
				//		if (currentform && currentform->formType == RE::ENUM_FORM_ID::kAMMO) {
				//			curobj->weaponData.ammo = (RE::TESAmmo*)currentform;
				//			logger::debug(FMT_STRING("weapon formid: {:08X} {} changed ammo {:08X} {} "), curobj->formID, curobj->fullName, ((RE::TESAmmo*)currentform)->formID, ((RE::TESAmmo*)currentform)->fullName);
				//		}
				//	}
				//}
				//if (found && !line.ammoList.empty()) {
				//	for (size_t i = 0; i < line.ammo.size(); i++) {
				//		RE::TESForm* currentform = nullptr;
				//		std::string string_form = line.ammoList[i];
				//		currentform = GetFormFromIdentifier(string_form);
				//		if (currentform && currentform->formType == RE::ENUM_FORM_ID::kLVLI) {
				//			curobj->weaponData.npcAddAmmoList = (RE::TESLevItem*)currentform;
				//			logger::debug(FMT_STRING("weapon formid: {:08X} {} change npc ammo list {:08X}  "), curobj->formID, curobj->fullName, ((RE::TESLevItem*)currentform)->formID);
				//		}
				//	}
				//}
				//if (found && !line.aimModel.empty()) {
				//	//logger::info(FMT_STRING("Processing Spell list size {}"), line.spellsToAdd.size());
				//	//for (const auto& avifstring : line.avifs)
				//	for (size_t i = 0; i < line.aimModel.size(); i++) {
				//		RE::TESForm* currentform = nullptr;
				//		std::string string_form = line.aimModel[i];
				//		currentform = GetFormFromIdentifier(string_form);
				//		//logger::info(FMT_STRING("weapon formid: {:08X} {} checking aim model...  "), curnpc->formID, curnpc->fullName);
				//		if (currentform && currentform->formType == RE::ENUM_FORM_ID::kAMDL) {
				//			// currentform->As<RE::BGSAimModel>() &&
				//			auto cAimModel = fallout_cast<RE::BGSAimModel*>(currentform);
				//			if (cAimModel) {
				//				curobj->weaponData.aimModel = cAimModel;
				//				logger::debug(FMT_STRING("weapon formid: {:08X} {} changed aim model to {:08X}  "), curobj->formID, curobj->fullName, (currentform)->formID);
				//			}
				//		}
				//	}
				//}

				//if (found && !line.damageTypes.empty()) {
				//	//logger::info("found! patching values");
				//	//for (const auto& avifstring : line.avifs)
				//	for (size_t i = 0; i < line.damageTypes.size(); i++) {
				//		RE::TESForm* currentform = nullptr;
				//		std::string string_form = line.damageTypes[i];
				//		currentform = GetFormFromIdentifier(string_form);
				//		if (currentform && currentform->formType == RE::ENUM_FORM_ID::kDMGT) {
				//			//logger::info("avif valid!");
				//			float finalValue = 0;


				//				if (!line.values1.empty() && !line.values2.empty()) {
				//					finalValue = floor((std::rand() / static_cast<float>(RAND_MAX)) * (line.values2[i] - line.values1[i] + 1) + line.values1[i]);
				//				}

				//			changeDamageType_Weapon(curobj, (RE::BGSDamageType*)currentform, finalValue);
				//			logger::debug(FMT_STRING("weapon formid: {:08X} {} changed damage type {:08X} to {}"), curobj->formID, curobj->fullName, ((RE::BGSDamageType*)currentform)->formID, finalValue);
				//		}
				//	}
				//}
				//
				//if (found && !line.fullName.empty() && line.fullName != "none") {
				//	try {
				//		logger::debug(FMT_STRING("weapon formid: {:08X} {} changed fullname to {}"), curobj->formID, curobj->fullName, line.fullName);
				//		curobj->fullName = line.fullName;
				//	} catch (const std::invalid_argument& e) {
				//	}
				//}
				//if (found) {
				//	const auto dataHandler = RE::TESDataHandler::GetSingleton();
				//	RE::BSTArray<RE::TESObjectREFR*> refs = dataHandler->GetFormArray<RE::TESObjectREFR>();
				//	logger::debug(FMT_STRING("weapon instanceData count {}"), refs.size());
				//	for (const auto& ref : refs) {
				//		logger::debug(FMT_STRING("weapon instanceData curobj {:08X} ref {:08X} base formID {:08X}"), curobj->formID, ref->formID, ref->GetObjectReference()->formID);
				//		if (ref->GetObjectReference()->formID == curobj->formID) {
				//			ref->extraList->RemoveExtra(RE::EXTRA_DATA_TYPE::kInstanceData);
				//			logger::debug(FMT_STRING("weapon instanceData ref {:08X} base formID {:08X}"), ref->formID, ref->GetObjectReference()->formID);
				//		}
				//	}

				//}

				
				
				//const std::string testB = "Fallout4.esm|0004C922";
				//RE::TESForm* test11 = GetFormFromIdentifier(testB);
				//RE::BGSKeyword* testk = (RE::BGSKeyword*)test11;
				//const std::string ref = "CorvalhoWidowShotgun.esp|3E00E603";
				//RE::TESForm* refForm = GetFormFromIdentifier(ref);
				//if (0x3E0044EA == curobj->formID) {
				//	RE::TESObjectREFR* test1 = static_cast<RE::TESObjectREFR*>(refForm);
				//	RE::TESBoundObject* ref = test1->GetObjectReference();
				//	RE::TESObjectWEAP* weap = ref->As<RE::TESObjectWEAP>();
				//	//auto instanceDataCopy = *(weap->GetBaseInstanceData());
				//	//test1->extraList->SetInstanceData(&instanceDataCopy, ref);
				//	test1->extraList->RemoveExtra(RE::EXTRA_DATA_TYPE::kInstanceData);
				//	//test1->extraList->CreateInstanceData(weap, false);
				//	//RE::BaseExtraList::RemoveExtra //test1->
				//	//RE::TESObjectWEAP::InstanceData::CreateKeywordData
				//	//weap->weaponData.attackDamage = 1;
				//	logger::debug(FMT_STRING(" formID {:08X} {:08X} {:08X} {}"), test1->formID, weap->formID, ref->formID, weap->weaponData.attackDamage);
				//} else {
				//	logger::debug("Failed to get form from identifier");
				//	//aidatauto weap = (RE::TESObjectWEAP*)test1->GetHandle().get().get();
				//	//auto BO = test1->GetObjectReference();
				//	//auto weap = BO->As<RE::TESObjectWEAP>();
				//	//weap->weaponData = ((RE::TESObjectWEAP*)test11)->weaponData;
				//}


			}
		}
	}

	/*void* readConfigWeapon()
	{
		logger::debug("Reading config and create forms...");

		char skipChar = '/';
		std::string extension = ".ini";
		DIR* dir;
		struct dirent* ent;
		std::string folder = ".\\Data\\F4se\\Plugins\\RobCo_Patcher\\weapon\\";

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
					std::list<patch_instruction_weapon> tokens;
					infile.open(folder + ent->d_name);
					while (std::getline(infile, line)) {
						if (line[0] == skipChar) {
							continue;
						}

						if (line.empty()) {
							continue;
						}

						tokens.push_back(create_patch_instructions_weapon(line));
					}
					infile.close();
					process_patch_instructions_weapon(tokens);
				}
			}
			closedir(dir);
		} else {
			logger::info("Couldn't find weapon dir.");
		}

		return 0;
	}*/

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

									tokens.push_back(create_patch_instructions(line));
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

	void* patch(WEAPONS::patch_instruction line, RE::TESObjectWEAP* curobj)
	{
		if (!line.attackDamage.empty() && line.attackDamage != "none") {
			try {
				curobj->weaponData.attackDamage = std::stof(line.attackDamage);
				logger::debug(FMT_STRING("weapon formid: {:08X} {} changed damage {}"), curobj->formID, curobj->fullName, curobj->weaponData.attackDamage);
			} catch (const std::invalid_argument& e) {
			}
		}
		if (!line.weight.empty() && line.weight != "none") {
			try {
				curobj->weaponData.weight = std::stof(line.weight);
				logger::debug(FMT_STRING("weapon formid: {:08X} {} changed weight {}"), curobj->formID, curobj->fullName, curobj->weaponData.weight);
			} catch (const std::invalid_argument& e) {
			}
		}
		if (!line.capsvalue.empty() && line.capsvalue != "none") {
			try {
				curobj->weaponData.value = std::stof(line.capsvalue);
				logger::debug(FMT_STRING("weapon formid: {:08X} {} changed value {}"), curobj->formID, curobj->fullName, curobj->weaponData.value);
			} catch (const std::invalid_argument& e) {
			}
		}
		if (!line.actionpointcost.empty() && line.actionpointcost != "none") {
			try {
				curobj->weaponData.attackActionPointCost = std::stof(line.actionpointcost);
				logger::debug(FMT_STRING("weapon formid: {:08X} {} changed attack actionpoint cost {}"), curobj->formID, curobj->fullName, curobj->weaponData.attackActionPointCost);
			} catch (const std::invalid_argument& e) {
			}
		}

		if (!line.hittype.empty() && line.hittype != "none") {
			try {
				std::string hittypeLower = line.hittype;
				std::transform(hittypeLower.begin(), hittypeLower.end(), hittypeLower.begin(), [](unsigned char c) {
					return std::tolower(c);  // convert to lowercase
				});

				if (hittypeLower == "normal") {
					curobj->weaponData.hitBehavior = RE::WEAPONHITBEHAVIOR::kNormal;
					logger::debug(FMT_STRING("weapon formid: {:08X} {} changed hit behavior to normal"), curobj->formID, curobj->fullName);
				} else if (hittypeLower == "dismemberonly" || hittypeLower == "dismember") {
					curobj->weaponData.hitBehavior = RE::WEAPONHITBEHAVIOR::kDismemberOnly;
					logger::debug(FMT_STRING("weapon formid: {:08X} {} changed hit behavior to dismember only"), curobj->formID, curobj->fullName);
				} else if (hittypeLower == "explodeOnly" || hittypeLower == "explode") {
					curobj->weaponData.hitBehavior = RE::WEAPONHITBEHAVIOR::kExplodeOnly;
					logger::debug(FMT_STRING("weapon formid: {:08X} {} changed hit behavior to explode only"), curobj->formID, curobj->fullName);
				} else if (hittypeLower == "nodismemberorexplode" || hittypeLower == "no") {
					curobj->weaponData.hitBehavior = RE::WEAPONHITBEHAVIOR::kNoDismemberOrExplode;
					logger::debug(FMT_STRING("weapon formid: {:08X} {} changed hit behavior to no dismember or explode"), curobj->formID, curobj->fullName);
				}

			} catch (const std::invalid_argument& e) {
			}
		}

		if (!line.soundlevel.empty() && line.soundlevel != "none") {
			try {
				std::string hittypeLower = line.soundlevel;
				std::transform(hittypeLower.begin(), hittypeLower.end(), hittypeLower.begin(), [](unsigned char c) {
					return std::tolower(c);  // convert to lowercase
				});

				if (hittypeLower == "loud") {
					curobj->weaponData.soundLevel = RE::SOUND_LEVEL::kLoud;
					logger::debug(FMT_STRING("weapon formid: {:08X} {} changed sound level to loud"), curobj->formID, curobj->fullName);
				} else if (hittypeLower == "normal") {
					curobj->weaponData.soundLevel = RE::SOUND_LEVEL::kNormal;
					logger::debug(FMT_STRING("weapon formid: {:08X} {} changed sound level to normal"), curobj->formID, curobj->fullName);
				} else if (hittypeLower == "silent") {
					curobj->weaponData.soundLevel = RE::SOUND_LEVEL::kSilent;
					logger::debug(FMT_STRING("weapon formid: {:08X} {} changed sound level to silent"), curobj->formID, curobj->fullName);
				} else if (hittypeLower == "veryload") {
					curobj->weaponData.soundLevel = RE::SOUND_LEVEL::kVeryLoud;
					logger::debug(FMT_STRING("weapon formid: {:08X} {} changed sound level to very load"), curobj->formID, curobj->fullName);
				} else if (hittypeLower == "quiet") {
					curobj->weaponData.soundLevel = RE::SOUND_LEVEL::kQuiet;
					logger::debug(FMT_STRING("weapon formid: {:08X} {} changed sound level to quiet"), curobj->formID, curobj->fullName);
				}

			} catch (const std::invalid_argument& e) {
			}
		}

		if (!line.bashDamage.empty() && line.bashDamage != "none") {
			try {
				curobj->weaponData.secondaryDamage = std::stof(line.bashDamage);
				logger::debug(FMT_STRING("weapon formid: {:08X} {} changed damage {}"), curobj->formID, curobj->fullName, curobj->weaponData.secondaryDamage);
			} catch (const std::invalid_argument& e) {
			}
		}

		if (!line.accuracyMult.empty() && line.accuracyMult != "none" && curobj->weaponData.aimModel) {
			try {
				curobj->weaponData.aimModel->aimModelData.aimModelConeIronSightsMultiplier = std::stof(line.accuracyMult);
				logger::debug(FMT_STRING("weapon formid: {:08X} {} changed aimModelConeIronSightsMultiplier {}"), curobj->formID, curobj->fullName, curobj->weaponData.aimModel->aimModelData.aimModelConeIronSightsMultiplier);
			} catch (const std::invalid_argument& e) {
			}
		}

		if (!line.springBackMult.empty() && line.springBackMult != "none" && curobj->weaponData.aimModel) {
			try {
				curobj->weaponData.aimModel->aimModelData.aimModelRecoilDiminishSpringForce = std::stof(line.springBackMult);
				logger::debug(FMT_STRING("weapon formid: {:08X} {} changed aimModelRecoilDiminishSpringForce {}"), curobj->formID, curobj->fullName, curobj->weaponData.aimModel->aimModelData.aimModelRecoilDiminishSpringForce);
			} catch (const std::invalid_argument& e) {
			}
		}

		if (!line.recoilPerShotMin.empty() && line.recoilPerShotMin != "none" && curobj->weaponData.aimModel) {
			try {
				curobj->weaponData.aimModel->aimModelData.aimModelRecoilMinDegPerShot = std::stof(line.recoilPerShotMin);
				logger::debug(FMT_STRING("weapon formid: {:08X} {} changed aimModelRecoilMinDegPerShot {}"), curobj->formID, curobj->fullName, curobj->weaponData.aimModel->aimModelData.aimModelRecoilMinDegPerShot);
			} catch (const std::invalid_argument& e) {
			}
		}

		if (!line.recoilPerShotMax.empty() && line.recoilPerShotMax != "none" && curobj->weaponData.aimModel) {
			try {
				curobj->weaponData.aimModel->aimModelData.aimModelRecoilMaxDegPerShot = std::stof(line.recoilPerShotMax);
				logger::debug(FMT_STRING("weapon formid: {:08X} {} changed aimModelRecoilMaxDegPerShot {}"), curobj->formID, curobj->fullName, curobj->weaponData.aimModel->aimModelData.aimModelRecoilMaxDegPerShot);
			} catch (const std::invalid_argument& e) {
			}
		}

		if (!line.outOfRangeDamageMult.empty() && line.outOfRangeDamageMult != "none") {
			try {
				curobj->weaponData.outOfRangeDamageMult = std::stof(line.outOfRangeDamageMult);
				logger::debug(FMT_STRING("weapon formid: {:08X} {} changed outOfRangeDamageMult {}"), curobj->formID, curobj->fullName, curobj->weaponData.outOfRangeDamageMult);
			} catch (const std::invalid_argument& e) {
			}
		}
		if (!line.attachParentSlotKeywordsToAdd.empty()) {
			//logger::info("found! patching values");
			//for (const auto& avifstring : line.avifs)
			for (size_t i = 0; i < line.attachParentSlotKeywordsToAdd.size(); i++) {
				RE::TESForm* currentform = nullptr;
				std::string string_form = line.attachParentSlotKeywordsToAdd[i];
				currentform = GetFormFromIdentifier(string_form);
				if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
					if (!curobj->attachParents.HasKeyword((RE::BGSKeyword*)currentform)) {
						curobj->attachParents.AddKeyword((RE::BGSKeyword*)currentform);
						logger::debug(FMT_STRING("weapon formid: {:08X} {} added attach parent slot keyword {:08X} {} "), curobj->formID, curobj->fullName, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
					}
				}
			}
		}
		if (!line.attachParentSlotKeywordsToRemove.empty()) {
			for (size_t i = 0; i < line.attachParentSlotKeywordsToRemove.size(); i++) {
				RE::TESForm* currentform = nullptr;
				std::string string_form = line.attachParentSlotKeywordsToRemove[i];
				currentform = GetFormFromIdentifier(string_form);
				if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
					if (!curobj->attachParents.HasKeyword((RE::BGSKeyword*)currentform)) {
						curobj->attachParents.RemoveKeyword((RE::BGSKeyword*)currentform);

						logger::debug(FMT_STRING("armor formid: {:08X} removed attach parent slot keyword {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
					}
				}
			}
		}
		if (!line.keywordsToAdd.empty()) {
			for (size_t i = 0; i < line.keywordsToAdd.size(); i++) {
				RE::TESForm* currentform = nullptr;
				std::string string_form = line.keywordsToAdd[i];
				currentform = GetFormFromIdentifier(string_form);
				if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
					curobj->AddKeyword((RE::BGSKeyword*)currentform);
					logger::debug(FMT_STRING("weapon formid: {:08X} {} added keyword {:08X} {} "), curobj->formID, curobj->fullName, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
				}
			}
		}

		if (!line.keywordsToRemove.empty()) {
			for (size_t i = 0; i < line.keywordsToRemove.size(); i++) {
				RE::TESForm* currentform = nullptr;
				std::string string_form = line.keywordsToRemove[i];
				currentform = GetFormFromIdentifier(string_form);
				if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
					curobj->RemoveKeyword((RE::BGSKeyword*)currentform);
					logger::debug(FMT_STRING("weapon formid: {:08X} removed keyword {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
				}
			}
		}

		if (!line.ammo.empty()) {
			//logger::info(FMT_STRING("found in ammo {}"), found);
			for (size_t i = 0; i < line.ammo.size(); i++) {
				//logger::info(FMT_STRING("found in ammo {} {}"), line.ammo.size(), line.ammo[i]);
				RE::TESForm* currentform = nullptr;
				std::string string_form = line.ammo[i];
				currentform = GetFormFromIdentifier(string_form);
				if (currentform && currentform->formType == RE::ENUM_FORM_ID::kAMMO) {
					curobj->weaponData.ammo = (RE::TESAmmo*)currentform;
					logger::debug(FMT_STRING("weapon formid: {:08X} {} changed ammo {:08X} {} "), curobj->formID, curobj->fullName, ((RE::TESAmmo*)currentform)->formID, ((RE::TESAmmo*)currentform)->fullName);
				}
			}
		}
		if (!line.ammoList.empty()) {
			for (size_t i = 0; i < line.ammo.size(); i++) {
				RE::TESForm* currentform = nullptr;
				std::string string_form = line.ammoList[i];
				currentform = GetFormFromIdentifier(string_form);
				if (currentform && currentform->formType == RE::ENUM_FORM_ID::kLVLI) {
					curobj->weaponData.npcAddAmmoList = (RE::TESLevItem*)currentform;
					logger::debug(FMT_STRING("weapon formid: {:08X} {} change npc ammo list {:08X}  "), curobj->formID, curobj->fullName, ((RE::TESLevItem*)currentform)->formID);
				}
			}
		}
		if (!line.aimModel.empty()) {
			//logger::info(FMT_STRING("Processing Spell list size {}"), line.spellsToAdd.size());
			//for (const auto& avifstring : line.avifs)
			for (size_t i = 0; i < line.aimModel.size(); i++) {
				RE::TESForm* currentform = nullptr;
				std::string string_form = line.aimModel[i];
				currentform = GetFormFromIdentifier(string_form);
				//logger::info(FMT_STRING("weapon formid: {:08X} {} checking aim model...  "), curnpc->formID, curnpc->fullName);
				if (currentform && currentform->formType == RE::ENUM_FORM_ID::kAMDL) {
					// currentform->As<RE::BGSAimModel>() &&
					auto cAimModel = fallout_cast<RE::BGSAimModel*>(currentform);
					if (cAimModel) {
						curobj->weaponData.aimModel = cAimModel;
						logger::debug(FMT_STRING("weapon formid: {:08X} {} changed aim model to {:08X}  "), curobj->formID, curobj->fullName, (currentform)->formID);
					}
				}
			}
		}

		if (!line.damageTypes.empty()) {
			//logger::info("found! patching values");
			//for (const auto& avifstring : line.avifs)
			for (size_t i = 0; i < line.damageTypes.size(); i++) {
				RE::TESForm* currentform = nullptr;
				std::string string_form = line.damageTypes[i];
				currentform = GetFormFromIdentifier(string_form);
				if (currentform && currentform->formType == RE::ENUM_FORM_ID::kDMGT) {
					//logger::info("avif valid!");
					float finalValue = 0;

					if (!line.values1.empty() && !line.values2.empty()) {
						finalValue = floor((std::rand() / static_cast<float>(RAND_MAX)) * (line.values2[i] - line.values1[i] + 1) + line.values1[i]);
					}

					changeDamageType_Weapon(curobj, (RE::BGSDamageType*)currentform, finalValue);
					logger::debug(FMT_STRING("weapon formid: {:08X} {} changed damage type {:08X} to {}"), curobj->formID, curobj->fullName, ((RE::BGSDamageType*)currentform)->formID, finalValue);
				}
			}
		}

		if (!line.damageTypesToRemove.empty()) {
			//logger::info("found! patching values");
			//for (const auto& avifstring : line.avifs)
			for (size_t i = 0; i < line.damageTypesToRemove.size(); i++) {
				RE::TESForm* currentform = nullptr;
				std::string string_form = line.damageTypesToRemove[i];
				currentform = GetFormFromIdentifier(string_form);
				if (currentform && currentform->formType == RE::ENUM_FORM_ID::kDMGT) {
					//logger::info("avif valid!");
					eraseDamageType_Weapon(curobj, (RE::BGSDamageType*)currentform);
					logger::debug(FMT_STRING("weapon formid: {:08X} {} removed damage types {:08X}"), curobj->formID, curobj->fullName, ((RE::BGSDamageType*)currentform)->formID);
				}
			}
		}

		if (!line.fullName.empty() && line.fullName != "none") {
			try {
				logger::debug(FMT_STRING("weapon formid: {:08X} {} changed fullname to {}"), curobj->formID, curobj->fullName, line.fullName);
				curobj->fullName = line.fullName;
			} catch (const std::invalid_argument& e) {
			}
		}

		if (!line.overrideProjectile.empty() && line.overrideProjectile != "none") {
			RE::TESForm* currentform = nullptr;
			std::string string_form = line.overrideProjectile;
			currentform = GetFormFromIdentifier(string_form);
			//logger::debug(FMT_STRING("Projectile -> {}"), string_form);
			if (currentform && currentform->formType == RE::ENUM_FORM_ID::kPROJ) {
				curobj->weaponData.rangedData->overrideProjectile = (RE::BGSProjectile*)currentform;
				logger::debug(FMT_STRING("weapon formid: {:08X} changed overrideProjectile to {:08X} "), curobj->formID, ((RE::BGSProjectile*)currentform)->formID);
			} else if (toLowerCase(line.overrideProjectile) == "null") {
				curobj->weaponData.rangedData->overrideProjectile = nullptr;
				logger::debug(FMT_STRING("weapon formid: {:08X} changed overrideProjectile to null (none) "), curobj->formID);
			}
		}


	}

}

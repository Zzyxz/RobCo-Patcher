#include "object_omod.h"
#include <utility.h>
using namespace RE::detail;
namespace OMOD
{

	struct line_content create_patch_instruction(const std::string& line)
	{
		line_content l;

		// extract connectionAnd
		std::regex connectionAnd_regex("filterConnection\\s*=([^:]+)", regex::icase);
		std::smatch connectionAnd_match;
		std::regex_search(line, connectionAnd_match, connectionAnd_regex);
		// extract the value after the equals sign
		if (connectionAnd_match.empty() || connectionAnd_match[1].str().empty()) {
		} else {
			std::string value = connectionAnd_match[1].str();
			//value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			std::stringstream ss(value);
			std::string item;
			while (std::getline(ss, item, ',')) {
				item.erase(item.begin(), std::find_if_not(item.begin(), item.end(), ::isspace));
				item.erase(std::find_if_not(item.rbegin(), item.rend(), ::isspace).base(), item.end());
				//logger::debug(FMT_STRING("SearchString {}"), item);
				l.connectionAnd = item;
			}
		}

		// extract objects
		std::regex objects_regex("filterByOMod\\s*=([^:]+)", regex::icase);
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

		// extract targetType
		std::regex targetType_regex("filterByFormType\\s*=([^:]+)", regex::icase);
		std::smatch targetTypematch;
		std::regex_search(line, targetTypematch, targetType_regex);
		// extract the value after the equals sign
		if (targetTypematch.empty() || targetTypematch[1].str().empty()) {
			l.targetType = "none";
		} else {
			std::string value = targetTypematch[1].str();
			value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			l.targetType = value;
		}



					// extract FormAnd
		std::regex FormAnd_regex("filterByForms\\s*=([^:]+)", regex::icase);
		std::smatch FormAnd_match;
		std::regex_search(line, FormAnd_match, FormAnd_regex);
		// extract the value after the equals sign
		if (FormAnd_match.empty() || FormAnd_match[1].str().empty()) {
		} else {
			std::string value = FormAnd_match[1].str();
			//value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			std::stringstream ss(value);
			std::string item;
			while (std::getline(ss, item, ',')) {
				item.erase(item.begin(), std::find_if_not(item.begin(), item.end(), ::isspace));
				item.erase(std::find_if_not(item.rbegin(), item.rend(), ::isspace).base(), item.end());
				//logger::debug(FMT_STRING("SearchString {}"), item);
				l.FormAnd.push_back(item);
			}
		}

				// extract PropertyAnd
		std::regex PropertyAnd_regex("filterByPropertiesAnd\\s*=([^:]+)", regex::icase);
		std::smatch PropertyAnd_match;
		std::regex_search(line, PropertyAnd_match, PropertyAnd_regex);
		// extract the value after the equals sign
		if (PropertyAnd_match.empty() || PropertyAnd_match[1].str().empty()) {
		} else {
			std::string value = PropertyAnd_match[1].str();
			//value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			std::stringstream ss(value);
			std::string item;
			while (std::getline(ss, item, ',')) {
				item.erase(item.begin(), std::find_if_not(item.begin(), item.end(), ::isspace));
				item.erase(std::find_if_not(item.rbegin(), item.rend(), ::isspace).base(), item.end());
				//logger::debug(FMT_STRING("SearchString {}"), item);
				l.PropertyAnd.push_back(item);
			}
		}

				// extract PropertyOr
		std::regex PropertyOr_regex("filterByPropertiesOr\\s*=([^:]+)", regex::icase);
		std::smatch PropertyOr_match;
		std::regex_search(line, PropertyOr_match, PropertyOr_regex);
		// extract the value after the equals sign
		if (PropertyOr_match.empty() || PropertyOr_match[1].str().empty()) {
		} else {
			std::string value = PropertyOr_match[1].str();
			//value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			std::stringstream ss(value);
			std::string item;
			while (std::getline(ss, item, ',')) {
				item.erase(item.begin(), std::find_if_not(item.begin(), item.end(), ::isspace));
				item.erase(std::find_if_not(item.rbegin(), item.rend(), ::isspace).base(), item.end());
				//logger::debug(FMT_STRING("SearchString {}"), item);
				l.PropertyOr.push_back(item);
			}
		}

				// extract PropertyExclude
		std::regex PropertyExclude_regex("filterByPropertiesExclude\\s*=([^:]+)", regex::icase);
		std::smatch PropertyExclude_match;
		std::regex_search(line, PropertyExclude_match, PropertyExclude_regex);
		// extract the value after the equals sign
		if (PropertyExclude_match.empty() || PropertyExclude_match[1].str().empty()) {
		} else {
			std::string value = PropertyExclude_match[1].str();
			//value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			std::stringstream ss(value);
			std::string item;
			while (std::getline(ss, item, ',')) {
				item.erase(item.begin(), std::find_if_not(item.begin(), item.end(), ::isspace));
				item.erase(std::find_if_not(item.rbegin(), item.rend(), ::isspace).base(), item.end());
				//logger::debug(FMT_STRING("SearchString {}"), item);
				l.PropertyExclude.push_back(item);
			}
		}

			// extract stringContainsAnd
		std::regex stringContainsAnd_regex("filterByNameContainsAnd\\s*=([^:]+)", regex::icase);
		std::smatch stringContainsAnd_match;
		std::regex_search(line, stringContainsAnd_match, stringContainsAnd_regex);
		// extract the value after the equals sign
		if (stringContainsAnd_match.empty() || stringContainsAnd_match[1].str().empty()) {
		} else {
			std::string value = stringContainsAnd_match[1].str();
			//value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			std::stringstream ss(value);
			std::string item;
			while (std::getline(ss, item, ',')) {
				item.erase(item.begin(), std::find_if_not(item.begin(), item.end(), ::isspace));
				item.erase(std::find_if_not(item.rbegin(), item.rend(), ::isspace).base(), item.end());
				//logger::debug(FMT_STRING("SearchString {}"), item);
				l.stringContainsAnd.push_back(item);
			}
		}

					// extract stringContainsOr
		std::regex stringContainsOr_regex("filterByNameContainsOr\\s*=([^:]+)", regex::icase);
		std::smatch stringContainsOr_match;
		std::regex_search(line, stringContainsOr_match, stringContainsOr_regex);
		// extract the value after the equals sign
		if (stringContainsOr_match.empty() || stringContainsOr_match[1].str().empty()) {
		} else {
			std::string value = stringContainsOr_match[1].str();
			//value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			std::stringstream ss(value);
			std::string item;
			while (std::getline(ss, item, ',')) {
				item.erase(item.begin(), std::find_if_not(item.begin(), item.end(), ::isspace));
				item.erase(std::find_if_not(item.rbegin(), item.rend(), ::isspace).base(), item.end());
				l.stringContainsOr.push_back(item);
			}
		}

		// extract stringContainsExclude
		std::regex stringContainsExclude_regex("filterByNameContainsExclude\\s*=([^:]+)", regex::icase);
		std::smatch stringContainsExclude_match;
		std::regex_search(line, stringContainsExclude_match, stringContainsExclude_regex);
		// extract the value after the equals sign
		if (stringContainsExclude_match.empty() || stringContainsExclude_match[1].str().empty()) {
		} else {
			std::string value = stringContainsExclude_match[1].str();
			//value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			std::stringstream ss(value);
			std::string item;
			while (std::getline(ss, item, ',')) {
				item.erase(item.begin(), std::find_if_not(item.begin(), item.end(), ::isspace));
				item.erase(std::find_if_not(item.rbegin(), item.rend(), ::isspace).base(), item.end());
				l.stringContainsExclude.push_back(item);
			}
		}

				// extract keywords
		std::regex keywords_regex("filterByAttachPoint\\s*=([^:]+)", regex::icase);
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
			l.attachPointKeywordsFilter = keywords;
		}

		std::regex property_regex("changeOModPropertiesFloat\\s*=([^:]+)", regex::icase);
		std::smatch property_match;
		std::regex_search(line, property_match, property_regex);
		std::vector<std::string> property;
		if (property_match.empty() || property_match[1].str().empty()) {
			//empty
		} else {
			std::string property_str = property_match[1];
			std::regex pattern("(\\w+)\\s*=\\s*([^,]+)", regex::icase);
			std::smatch match;

			auto begin = std::sregex_iterator(property_str.begin(), property_str.end(), pattern);
			auto end = std::sregex_iterator();

			for (std::sregex_iterator i = begin; i != end; ++i) {
				std::smatch match = *i;
				l.properties.push_back(match[1]);
				l.propertiesValues.push_back(match[2]);
				//logger::debug(FMT_STRING("Match: {} {}"), match[1].str(), match[2].str());
			}
		}

		std::regex propertyVP_regex("changeOModPropertiesVP\\s*=([^:]+)", regex::icase);
		std::smatch propertyVP_match;
		std::regex_search(line, propertyVP_match, propertyVP_regex);
		std::vector<std::string> propertyVP;
		if (propertyVP_match.empty() || propertyVP_match[1].str().empty()) {
			//empty
		} else {
			std::string propertyVP_str = propertyVP_match[1];
			std::regex pattern("([^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8})\\s*=\\s*([^,]+)", regex::icase);
			std::smatch match;

			auto begin = std::sregex_iterator(propertyVP_str.begin(), propertyVP_str.end(), pattern);
			auto end = std::sregex_iterator();

			for (std::sregex_iterator i = begin; i != end; ++i) {
				std::smatch match = *i;
				l.propertiesVP.push_back(match[1]);
				l.propertiesVPValues.push_back(match[2]);
				//logger::debug(FMT_STRING("Match: {} {}"), match[1].str(), match[2].str());
			}
		}

		std::regex propertyForm_regex("changeOModPropertiesForm\\s*=([^:]+)", regex::icase);
		std::smatch propertyForm_match;
		std::regex_search(line, propertyForm_match, propertyForm_regex);
		std::vector<std::string> propertyForm;
		if (propertyForm_match.empty() || propertyForm_match[1].str().empty()) {
			//empty
		} else {
			std::string propertyForm_str = propertyForm_match[1];
			std::regex pattern("([^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8})\\s*=\\s*([^,]+[ ]*[|][ ]*[a-zA-Z0-9]{1,8})", regex::icase);
			std::smatch match;

			auto begin = std::sregex_iterator(propertyForm_str.begin(), propertyForm_str.end(), pattern);
			auto end = std::sregex_iterator();

			for (std::sregex_iterator i = begin; i != end; ++i) {
				std::smatch match = *i;
				l.propertiesForm.push_back(match[1]);
				l.propertiesFormValues.push_back(match[2]);
				//logger::debug(FMT_STRING("Match: {} {}"), match[1].str(), match[2].str());
			}
		}

		// extract removeProperty
		std::regex removeProperty_regex("removeOModProperties\\s*=([^:]+)", regex::icase);
		std::smatch removeProperty_match;
		std::regex_search(line, removeProperty_match, removeProperty_regex);
		// extract the value after the equals sign
		if (removeProperty_match.empty() || removeProperty_match[1].str().empty()) {
		} else {
			std::string value = removeProperty_match[1].str();
			//value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			std::stringstream ss(value);
			std::string item;
			while (std::getline(ss, item, ',')) {
				item.erase(item.begin(), std::find_if_not(item.begin(), item.end(), ::isspace));
				item.erase(std::find_if_not(item.rbegin(), item.rend(), ::isspace).base(), item.end());
				//logger::debug(FMT_STRING("SearchString {}"), item);
				l.propertiesToRemove.push_back(item);
			}
		}

				// extract addProperty
		std::regex addProperty_regex("oModPropertiesToAdd\\s*=([^:]+)", regex::icase);
		std::smatch addProperty_match;
		std::regex_search(line, addProperty_match, addProperty_regex);
		// extract the value after the equals sign
		if (addProperty_match.empty() || addProperty_match[1].str().empty()) {
		} else {
			std::string value = addProperty_match[1].str();
			//value.erase(std::add_if(value.begin(), value.end(), ::isspace), value.end());
			std::stringstream ss(value);
			std::string item;
			while (std::getline(ss, item, ',')) {
				item.erase(item.begin(), std::find_if_not(item.begin(), item.end(), ::isspace));
				item.erase(std::find_if_not(item.rbegin(), item.rend(), ::isspace).base(), item.end());
				//logger::debug(FMT_STRING("SearchString {}"), item);
				l.propertiesToAdd.push_back(item);
			}
		}

				// extract removePropertyForm
		std::regex removePropertyForm_regex("removeOModPropertiesForm\\s*=([^:]+)", regex::icase);
		std::smatch removePropertyForm_match;
		std::regex_search(line, removePropertyForm_match, removePropertyForm_regex);
		// extract the value after the equals sign
		if (removePropertyForm_match.empty() || removePropertyForm_match[1].str().empty()) {
		} else {
			std::string value = removePropertyForm_match[1].str();
			//value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			std::stringstream ss(value);
			std::string item;
			while (std::getline(ss, item, ',')) {
				item.erase(item.begin(), std::find_if_not(item.begin(), item.end(), ::isspace));
				item.erase(std::find_if_not(item.rbegin(), item.rend(), ::isspace).base(), item.end());
				//logger::debug(FMT_STRING("SearchString {}"), item);
				l.propertiesToRemoveForm.push_back(item);
			}
		}

				// extract removePropertyPV
		std::regex removePropertyPV_regex("removeOModPropertiesVP\\s*=([^:]+)", regex::icase);
		std::smatch removePropertyPV_match;
		std::regex_search(line, removePropertyPV_match, removePropertyPV_regex);
		// extract the value after the equals sign
		if (removePropertyPV_match.empty() || removePropertyPV_match[1].str().empty()) {
		} else {
			std::string value = removePropertyPV_match[1].str();
			//value.erase(std::remove_if(value.begin(), value.end(), ::isspace), value.end());
			std::stringstream ss(value);
			std::string item;
			while (std::getline(ss, item, ',')) {
				item.erase(item.begin(), std::find_if_not(item.begin(), item.end(), ::isspace));
				item.erase(std::find_if_not(item.rbegin(), item.rend(), ::isspace).base(), item.end());
				//logger::debug(FMT_STRING("SearchString {}"), item);
				l.propertiesToRemovePV.push_back(item);
			}
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
			//logger::debug(FMT_STRING("omod filter {}"), l.fullName);
		}

		// extract functionType
		std::regex functionType_regex("changeOModFunctionType\\s*=([^:]+)", regex::icase);
		std::smatch functionType_match;
		std::regex_search(line, functionType_match, functionType_regex);
		std::vector<std::string> functionType;
		if (functionType_match.empty() || functionType_match[1].str().empty()) {
			//empty
		} else {
			std::string functionType_str = functionType_match[1];
			std::regex pattern("(\\w+)\\s*=\\s*([^,]+)", regex::icase);
			std::smatch match;

			auto begin = std::sregex_iterator(functionType_str.begin(), functionType_str.end(), pattern);
			auto end = std::sregex_iterator();

			for (std::sregex_iterator i = begin; i != end; ++i) {
				std::smatch match = *i;
				l.functionTypeProperties.push_back(match[1]);
				l.functionTypeValues.push_back(match[2]);
				//logger::debug(FMT_STRING("Match: {} {}"), match[1].str(), match[2].str());
			}
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

		// extract attachPoint
		std::regex attachPoint_regex("setAttachPoint\\s*=([^:]+)", regex::icase);
		std::smatch attachPointmatch;
		std::regex_search(line, attachPointmatch, attachPoint_regex);
		// extract the value after the equals sign
		if (attachPointmatch.empty() || attachPointmatch[1].str().empty()) {
			l.attachPoint = "none";
		} else {
			std::string keyword = attachPointmatch[1].str();
			keyword.erase(std::remove_if(keyword.begin(), keyword.end(), ::isspace), keyword.end());
			l.attachPoint = keyword;
		}

		// extract keywordsToAdd
		std::regex keywordsToAdd_regex("targetKeywordsToAdd\\s*=([^:]+)", regex::icase);
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
		std::regex keywordsToRemove_regex("targetKeywordsToRemove\\s*=([^:]+)", regex::icase);
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
		
		return l;
	}

	void process_patch_instructions(const std::list<line_content>& tokens)
	{
		logger::debug("processing patch instructions");
		const auto dataHandler = RE::TESDataHandler::GetSingleton();
		RE::BSTArray<RE::BGSMod::Attachment::Mod*> objectArray = dataHandler->GetFormArray<RE::BGSMod::Attachment::Mod>();
		for (const auto& line : tokens) {


		if (!line.objects.empty()) {
				//logger::info("npc not empty");
				for (const auto& objectstring : line.objects) {
					RE::TESForm* currentform = nullptr;
					RE::BGSMod::Attachment::Mod* object = nullptr;

					std::string string_form = objectstring;
					currentform = GetFormFromIdentifier(string_form);
					if (currentform && currentform->formType == RE::ENUM_FORM_ID::kOMOD) {
						object = (RE::BGSMod::Attachment::Mod*)currentform;
						patch(line, object);

					}
				}
			}

			if (!line.objects.empty() && line.stringContainsAnd.empty() && line.stringContainsOr.empty() && line.PropertyAnd.empty() && line.PropertyOr.empty()) {
				//logger::info("continue");
				continue;
			}

			for (const auto& curobj : objectArray) {
				bool found = false;
				bool stringAnd = false;
				bool stringOr = false;
				bool propertyAnd = false;
				bool propertyOr = false;
				bool connectionAnd = false;
				bool attachPoint = false;
				//
				//if (curobj->targetFormType == RE::ENUM_FORM_ID::kWEAP) {
				//	logger::debug(FMT_STRING("IS WEAP OMOD {:08X}"), curobj->formID);
				//} else if (curobj->targetFormType == RE::ENUM_FORM_ID::kARMO) {
				//	logger::debug(FMT_STRING("IS ARMO OMOD {:08X}"), curobj->formID);
				//}
				



				if (!line.targetType.empty() && line.targetType != "none") {
					if (toLowerCase(line.targetType) == "weapon" && curobj->targetFormType == RE::ENUM_FORM_ID::kARMO) {
						continue;
					} else if (toLowerCase(line.targetType) == "armor" && curobj->targetFormType == RE::ENUM_FORM_ID::kWEAP) {
						continue;
					}
				}

				if (!line.connectionAnd.empty() && line.connectionAnd != "none") {
					connectionAnd = true;
				}



				if (!line.stringContainsAnd.empty()) {
					//logger::info("keywords not empty");
					for (const auto& keywordstring : line.stringContainsAnd) {
						std::string searchString = keywordstring;
						std::string fullname = curobj->fullName.c_str();
						std::transform(searchString.begin(), searchString.end(), searchString.begin(), [](unsigned char c) { return std::tolower(c); });
						std::transform(fullname.begin(), fullname.end(), fullname.begin(), [](unsigned char c) { return std::tolower(c); });
						if (fullname.find(searchString) != std::string::npos) {
							stringAnd = true;
							//logger::info("OMOD found.");
						} else {
							stringAnd = false;
							break;
						}
					}
				} else {
					//logger::debug(FMT_STRING("KeywordAnd is empty, we pass true."));
					stringAnd = true;
				}
				if (!line.stringContainsOr.empty()) {
					//logger::info("keywords not empty");
					for (const auto& keywordstring : line.stringContainsOr) {
						std::string searchString = keywordstring;
						std::string fullname = curobj->fullName.c_str();
						std::transform(searchString.begin(), searchString.end(), searchString.begin(), [](unsigned char c) { return std::tolower(c); });
						std::transform(fullname.begin(), fullname.end(), fullname.begin(), [](unsigned char c) { return std::tolower(c); });
						if (fullname.find(searchString) != std::string::npos) {
							stringOr = true;
							break;
						}
					}
				} else {
					//logger::debug(FMT_STRING("KeywordOr is empty, we pass true."));
					stringOr = true;
				}

				if ((!line.stringContainsAnd.empty() || !line.stringContainsOr.empty()) && stringAnd && stringOr) {
					//logger::debug(FMT_STRING("Found true. {:08X} {}"), curobj->formID, curobj->fullName);
					found = true;
				} 

				if (!line.PropertyAnd.empty()) {
					//logger::info("PropertyAnd not empty");
					for (const auto& keywordstring : line.PropertyAnd) {

						int propertyId = getPropertyFromString(keywordstring);
						RE::BGSMod::Attachment::Mod::Data data;
						curobj->GetData(data);
						bool hasProperty = false;
						for (uint32_t j = 0; j < data.propertyModCount; j++) {
							auto& mod = data.propertyMods[j];
							if (propertyId == mod.target) {
								hasProperty = true;
							}
						}
						if (hasProperty) {
							propertyAnd = true;
							//logger::debug(FMT_STRING("omod propertyAnd {:08X} {} true"), curobj->formID, curobj->fullName);
						} else {
							propertyAnd = false;
							break;
						}

					}
				} else {
					//logger::debug(FMT_STRING("KeywordAnd is empty, we pass true."));
					propertyAnd = true;
				}

				if (!line.PropertyOr.empty()) {
					//logger::info("keywords not empty");
					for (const auto& keywordstring : line.PropertyOr) {

						int propertyId = getPropertyFromString(keywordstring);
						RE::BGSMod::Attachment::Mod::Data data;
						curobj->GetData(data);
						bool hasProperty = false;
						for (uint32_t j = 0; j < data.propertyModCount; j++) {
							auto& mod = data.propertyMods[j];
							if (propertyId == mod.target) {
								hasProperty = true;
							}
						}
						if (hasProperty) {
							propertyOr = true;
							//logger::debug(FMT_STRING("omod propertyOr {:08X} {} true"), curobj->formID, curobj->fullName);
							break;
						}

					}
				} else {
					//logger::debug(FMT_STRING("KeywordOr is empty, we pass true."));
					propertyOr = true;
				}

				if ((!line.PropertyAnd.empty() || !line.PropertyOr.empty()) && propertyAnd && propertyOr) {
					//logger::debug(FMT_STRING("Found a matching weapon by keywords. {:08X} {}"), curobj->formID, curobj->fullName);
					found = true;
				} 

				if (!line.attachPointKeywordsFilter.empty()) {
					for (const auto& keywordstring : line.attachPointKeywordsFilter) {
						RE::TESForm* currentform = nullptr;

						std::string string_form = keywordstring;
						currentform = GetFormFromIdentifier(string_form);
						auto attachPointKeyword = BGSKeywordGetTypedKeywordByIndex(RE::KeywordType::kAttachPoint, curobj->attachPoint.keywordIndex);
						if (currentform && attachPointKeyword && currentform->formID == attachPointKeyword->formID) {
							//logger::debug("attachPointKeywordsFilter IDxxx {:08X}", attachPointKeyword->formID);
							found = true;
							attachPoint = true;
							break;
						}
					}
				}

				if (connectionAnd ) {

					if ((!line.stringContainsAnd.empty() || !line.stringContainsOr.empty())) {
						//string = true;
						if (found && stringAnd && stringOr) {
							found = true;
						} else {
							found = false;
						}
					} 

					if ((!line.PropertyAnd.empty() || !line.PropertyOr.empty())) {
						//propertyString = true;
						if (found && propertyAnd && propertyOr) {
							found = true;
						} else {
							found = false;
						}
					} 

					if (!line.attachPointKeywordsFilter.empty()) {
						logger::debug("attachPointKeywordsFilter IDyyy");
						if (found && attachPoint) {
							found = true;
						} else {
							found = false;
						}
					}
				}
					

				if (line.objects.empty() && line.stringContainsAnd.empty() && line.stringContainsOr.empty() && line.PropertyAnd.empty() && line.PropertyOr.empty() && line.attachPointKeywordsFilter.empty()) {
					found = true;
				}

				if (!line.stringContainsExclude.empty()) {
					for (const auto& keywordstring : line.stringContainsExclude) {
						std::string searchString = keywordstring;
						std::string fullname = curobj->fullName.c_str();
						std::transform(searchString.begin(), searchString.end(), searchString.begin(), [](unsigned char c) { return std::tolower(c); });
						std::transform(fullname.begin(), fullname.end(), fullname.begin(), [](unsigned char c) { return std::tolower(c); });

						if (fullname.find(searchString) != std::string::npos) {
							found = false;
							//logger::debug(FMT_STRING("omod propertyExcluded {:08X} {}"), curobj->formID, curobj->fullName);
							break;
						}
					}
				}

				if (!line.PropertyExclude.empty()) {
					for (const auto& keywordstring : line.PropertyExclude) {
						int propertyId = getPropertyFromString(keywordstring);
						RE::BGSMod::Attachment::Mod::Data data;
						curobj->GetData(data);
						bool hasProperty = false;
						for (uint32_t j = 0; j < data.propertyModCount; j++) {
							auto& mod = data.propertyMods[j];
							if (propertyId == mod.target) {
								hasProperty = true;
							}
						}
						if (hasProperty) {
							found = false;
							//logger::debug(FMT_STRING("omod propertyExcluded {:08X} {}"), curobj->formID, curobj->fullName);
							break;
						} 
					}
				}

				//if (found && !line.properties.empty()) {
				//	for (uint32_t i = 0; i < line.properties.size(); i++) {
				//		int propertyId = getPropertyFromString(line.properties[i]);
				//		RE::BGSMod::Attachment::Mod::Data data;
				//		curobj->GetData(data);

				//		for (uint32_t j = 0; j < data.propertyModCount; j++) {
				//			auto& mod = data.propertyMods[j];
				//			auto type = mod.type;

				//			switch (type) {
				//			case RE::BGSMod::Property::TYPE::kInt:
				//				//logger::debug(FMT_STRING("OMOD Data Type {} kInt {} {} | {} {}"), std::to_string(mod.target), mod.data.mm.min.i, mod.data.mm.max.i, mod.data.mm.min.f, mod.data.mm.max.f);
				//				break;
				//			case RE::BGSMod::Property::TYPE::kFloat:
				//				if (propertyId == mod.target) {
				//					mod.data.mm.min.f = std::stof(line.propertiesValues[i]);
				//					logger::debug(FMT_STRING("omod {:08X} {} Value set {} to {}"), curobj->formID, curobj->fullName, line.properties[i], mod.data.mm.min.f);
				//				}
				//				break;
				//			case RE::BGSMod::Property::TYPE::kBool:
				//				//logger::debug(FMT_STRING("OMOD Data Editor ID {:08X}"), mod.data.fv.formID);
				//				break;
				//			case RE::BGSMod::Property::TYPE::kString:
				//				break;
				//			case RE::BGSMod::Property::TYPE::kForm:
				//				//if (mod.data.mm.min.i != 0)
				//				//	logger::debug(FMT_STRING("OMOD Data Type {} kForm Editor ID {:08X}"), std::to_string(mod.target), mod.data.form->formID);
				//				break;
				//			case RE::BGSMod::Property::TYPE::kEnum:
				//				break;
				//			case RE::BGSMod::Property::TYPE::kPair:
				//				//logger::debug(FMT_STRING("OMOD Data Type {} kPair {:08X} value {} fmin {} fmax {} imin {} imax {} "), std::to_string(mod.target), mod.data.fv.formID, mod.data.fv.value, mod.data.mm.min.f, mod.data.mm.max.f, mod.data.mm.min.i, mod.data.mm.max.i);
				//				//mod.data.fv.value = 20.0;
				//				//logger::debug(FMT_STRING("OMOD Data Type {} kPair {:08X} value {} fmin {} fmax {} imin {} imax {} "), std::to_string(mod.target), mod.data.fv.formID, mod.data.fv.value, mod.data.mm.min.f, mod.data.mm.max.f, mod.data.mm.min.i, mod.data.mm.max.i);
				//				break;
				//			}
				//		}
				//	}
				//}

				//if (found && !line.propertiesVP.empty()) {
				//	for (uint32_t i = 0; i < line.propertiesVP.size(); i++) {
				//		RE::BGSMod::Attachment::Mod::Data data;
				//		curobj->GetData(data);

				//		for (uint32_t j = 0; j < data.propertyModCount; j++) {
				//			auto& mod = data.propertyMods[j];
				//			auto type = mod.type;

				//			switch (type) {
				//			case RE::BGSMod::Property::TYPE::kInt:
				//				//logger::debug(FMT_STRING("OMOD Data Type {} kInt {} {} | {} {}"), std::to_string(mod.target), mod.data.mm.min.i, mod.data.mm.max.i, mod.data.mm.min.f, mod.data.mm.max.f);
				//				break;
				//			case RE::BGSMod::Property::TYPE::kFloat:
				//				break;
				//			case RE::BGSMod::Property::TYPE::kBool:
				//				//logger::debug(FMT_STRING("OMOD Data Editor ID {:08X}"), mod.data.fv.formID);
				//				break;
				//			case RE::BGSMod::Property::TYPE::kString:
				//				break;
				//			case RE::BGSMod::Property::TYPE::kForm:
				//				//if (mod.data.mm.min.i != 0)
				//				//	logger::debug(FMT_STRING("OMOD Data Type {} kForm Editor ID {:08X}"), std::to_string(mod.target), mod.data.form->formID);
				//				break;
				//			case RE::BGSMod::Property::TYPE::kEnum:
				//				break;
				//			case RE::BGSMod::Property::TYPE::kPair:
				//				RE::TESForm* currentform = GetFormFromIdentifier(line.propertiesVP[i]);
				//				if (currentform && mod.data.fv.formID == currentform->formID) {
				//					mod.data.fv.value = std::stof(line.propertiesVPValues[i]);
				//					logger::debug(FMT_STRING("omod {:08X} {} Value set {:08X} to {}"), curobj->formID, curobj->fullName, currentform->formID, mod.data.fv.value);
				//				}

				//				break;
				//			}
				//		}
				//	}
				//}

				//if (found && !line.propertiesForm.empty()) {
				//	for (uint32_t i = 0; i < line.propertiesForm.size(); i++) {
				//		RE::BGSMod::Attachment::Mod::Data data;
				//		curobj->GetData(data);

				//		for (uint32_t j = 0; j < data.propertyModCount; j++) {
				//			auto& mod = data.propertyMods[j];
				//			auto type = mod.type;

				//			switch (type) {
				//			case RE::BGSMod::Property::TYPE::kInt:
				//				//logger::debug(FMT_STRING("OMOD Data Type {} kInt {} {} | {} {}"), std::to_string(mod.target), mod.data.mm.min.i, mod.data.mm.max.i, mod.data.mm.min.f, mod.data.mm.max.f);
				//				break;
				//			case RE::BGSMod::Property::TYPE::kFloat:
				//				break;
				//			case RE::BGSMod::Property::TYPE::kBool:
				//				//logger::debug(FMT_STRING("OMOD Data Editor ID {:08X}"), mod.data.fv.formID);
				//				break;
				//			case RE::BGSMod::Property::TYPE::kString:
				//				break;
				//			case RE::BGSMod::Property::TYPE::kForm:
				//				if (mod.data.mm.min.i != 0) {
				//					RE::TESForm* currentform = GetFormFromIdentifier(line.propertiesForm[i]);
				//					RE::TESForm* currentformValue = GetFormFromIdentifier(line.propertiesFormValues[i]);
				//					if (currentform && currentformValue && mod.data.form->formID == currentform->formID) {
				//						mod.data.form = currentformValue;
				//						logger::debug(FMT_STRING("omod {:08X} {} changed form {:08X} to {:08X}"), curobj->formID, curobj->fullName, currentform->formID, currentformValue->formID);
				//					}
				//				}
				//				break;
				//			case RE::BGSMod::Property::TYPE::kEnum:
				//				break;
				//			case RE::BGSMod::Property::TYPE::kPair:


				//				break;
				//			}
				//		}
				//	}
				//}

				//if (found && !line.propertiesToRemoveForm.empty()) {
				//	for (uint32_t i = 0; i < line.propertiesToRemoveForm.size(); i++) {
				//		int propertyId = getPropertyFromString(line.propertiesToRemoveForm[i]);
				//		RE::BGSMod::Attachment::Mod::Data data;
				//		curobj->GetData(data);

				//		for (uint32_t j = 0; j < data.propertyModCount; j++) {
				//			auto& mod = data.propertyMods[j];
				//			auto type = mod.type;

				//			switch (type) {
				//			case RE::BGSMod::Property::TYPE::kForm:
				//				if (mod.data.mm.min.i != 0) {
				//					RE::TESForm* currentform = GetFormFromIdentifier(line.propertiesToRemoveForm[i]);
				//					if (currentform && mod.data.form->formID == currentform->formID) {
				//						mod.RemoveData();
				//						logger::debug(FMT_STRING("omod {:08X} {} Removed form {:08X}"), curobj->formID, curobj->fullName, currentform->formID);
				//					}
				//				}
				//				break;
				//			}
				//		}
				//	}
				//}

				//if (found && !line.propertiesToRemovePV.empty()) {
				//	for (uint32_t i = 0; i < line.propertiesToRemovePV.size(); i++) {
				//		int propertyId = getPropertyFromString(line.propertiesToRemovePV[i]);
				//		RE::BGSMod::Attachment::Mod::Data data;
				//		curobj->GetData(data);

				//		for (uint32_t j = 0; j < data.propertyModCount; j++) {
				//			auto& mod = data.propertyMods[j];
				//			auto type = mod.type;

				//			switch (type) {
				//			case RE::BGSMod::Property::TYPE::kPair:
				//				RE::TESForm* currentform = GetFormFromIdentifier(line.propertiesToRemovePV[i]);
				//					if (currentform && mod.data.fv.formID == currentform->formID) {
				//						mod.RemoveData();
				//						logger::debug(FMT_STRING("omod {:08X} {} Removed value pair {:08X}"), curobj->formID, curobj->fullName, currentform->formID);
				//					}
				//				break;
				//			}
				//		}
				//	}
				//}
				//if (found && !line.propertiesToRemove.empty()) {
				//	for (uint32_t i = 0; i < line.propertiesToRemove.size(); i++) {
				//		int propertyId = getPropertyFromString(line.propertiesToRemove[i]);
				//		RE::BGSMod::Attachment::Mod::Data data;
				//		curobj->GetData(data);

				//		for (uint32_t j = 0; j < data.propertyModCount; j++) {
				//			auto& mod = data.propertyMods[j];
				//			auto type = mod.type;

				//			if (propertyId == mod.target) {
				//				logger::debug(FMT_STRING("omod {:08X} {} removed property {}"), curobj->formID, curobj->fullName, line.propertiesToRemove[i]);
				//				mod.RemoveData();
				//			}
				//		}
				//	}
				//}


				//if (found && !line.fullName.empty() && line.fullName != "none") {
				//	try {
				//		logger::debug(FMT_STRING("omod formid: {:08X} {} changed fullname to {}"), curobj->formID, curobj->fullName, line.fullName);
				//		curobj->fullName = line.fullName;
				//	} catch (const std::invalid_argument& e) {
				//	}
				//}



				//if (found) {
				//	for (uint32_t i = 0; i < line.propertiesToRemove.size(); i++) {
				//		//int propertyId = getPropertyFromString(line.propertiesToRemove[i]);
				//		RE::BGSMod::Attachment::Mod::Data data;
				//		curobj->GetData(data);

				//		RE::BGSMod::Property::Mod test;
				//		test.data.

				//		logger::debug(FMT_STRING("omod {:08X} {} removed property {}"), curobj->formID, curobj->fullName, line.propertiesToRemove[i]);
				//		//for (uint32_t j = 0; j < data.propertyModCount; j++) {
				//		//	auto& mod = data.propertyMods[j];
				//		//	auto type = mod.type;
				//		//	//if (propertyId == mod.target) {
				//		//		//mod.RemoveData();
				//		//	//}
				//		//}
				//	}
				//}
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

	void* patch(OMOD::line_content line, RE::BGSMod::Attachment::Mod* curobj)
	{
		if (!line.properties.empty()) {
			for (uint32_t i = 0; i < line.properties.size(); i++) {
				int propertyId = getPropertyFromString(line.properties[i]);
				RE::BGSMod::Attachment::Mod::Data data;
				curobj->GetData(data);

				for (uint32_t j = 0; j < data.propertyModCount; j++) {
					auto& mod = data.propertyMods[j];
					auto type = mod.type;

					switch (type) {
					case RE::BGSMod::Property::TYPE::kInt:
						//logger::debug(FMT_STRING("OMOD Data Type {} kInt {} {} | {} {}"), std::to_string(mod.target), mod.data.mm.min.i, mod.data.mm.max.i, mod.data.mm.min.f, mod.data.mm.max.f);
						break;
					case RE::BGSMod::Property::TYPE::kFloat:
						if (propertyId == mod.target) {
							mod.data.mm.min.f = std::stof(line.propertiesValues[i]);
							logger::debug(FMT_STRING("omod {:08X} {} Value set {} to {}"), curobj->formID, curobj->fullName, line.properties[i], mod.data.mm.min.f);
						}
						break;
					case RE::BGSMod::Property::TYPE::kBool:
						//logger::debug(FMT_STRING("OMOD Data Editor ID {:08X}"), mod.data.fv.formID);
						break;
					case RE::BGSMod::Property::TYPE::kString:
						break;
					case RE::BGSMod::Property::TYPE::kForm:
						//if (mod.data.mm.min.i != 0)
						//	logger::debug(FMT_STRING("OMOD Data Type {} kForm Editor ID {:08X}"), std::to_string(mod.target), mod.data.form->formID);
						break;
					case RE::BGSMod::Property::TYPE::kEnum:
						break;
					case RE::BGSMod::Property::TYPE::kPair:
						//logger::debug(FMT_STRING("OMOD Data Type {} kPair {:08X} value {} fmin {} fmax {} imin {} imax {} "), std::to_string(mod.target), mod.data.fv.formID, mod.data.fv.value, mod.data.mm.min.f, mod.data.mm.max.f, mod.data.mm.min.i, mod.data.mm.max.i);
						//mod.data.fv.value = 20.0;
						//logger::debug(FMT_STRING("OMOD Data Type {} kPair {:08X} value {} fmin {} fmax {} imin {} imax {} "), std::to_string(mod.target), mod.data.fv.formID, mod.data.fv.value, mod.data.mm.min.f, mod.data.mm.max.f, mod.data.mm.min.i, mod.data.mm.max.i);
						break;
					}
				}
			}
		}

		if (!line.propertiesVP.empty()) {
			for (uint32_t i = 0; i < line.propertiesVP.size(); i++) {
				RE::BGSMod::Attachment::Mod::Data data;
				curobj->GetData(data);

				for (uint32_t j = 0; j < data.propertyModCount; j++) {
					auto& mod = data.propertyMods[j];
					auto type = mod.type;

					switch (type) {
					case RE::BGSMod::Property::TYPE::kInt:
						//logger::debug(FMT_STRING("OMOD Data Type {} kInt {} {} | {} {}"), std::to_string(mod.target), mod.data.mm.min.i, mod.data.mm.max.i, mod.data.mm.min.f, mod.data.mm.max.f);
						break;
					case RE::BGSMod::Property::TYPE::kFloat:
						break;
					case RE::BGSMod::Property::TYPE::kBool:
						//logger::debug(FMT_STRING("OMOD Data Editor ID {:08X}"), mod.data.fv.formID);
						break;
					case RE::BGSMod::Property::TYPE::kString:
						break;
					case RE::BGSMod::Property::TYPE::kForm:
						//if (mod.data.mm.min.i != 0)
						//	logger::debug(FMT_STRING("OMOD Data Type {} kForm Editor ID {:08X}"), std::to_string(mod.target), mod.data.form->formID);
						break;
					case RE::BGSMod::Property::TYPE::kEnum:
						break;
					case RE::BGSMod::Property::TYPE::kPair:
						RE::TESForm* currentform = GetFormFromIdentifier(line.propertiesVP[i]);
						if (currentform && mod.data.fv.formID == currentform->formID) {
							mod.data.fv.value = std::stof(line.propertiesVPValues[i]);
							logger::debug(FMT_STRING("omod {:08X} {} Value set {:08X} to {}"), curobj->formID, curobj->fullName, currentform->formID, mod.data.fv.value);
						}

						break;
					}
				}
			}
		}

		if (!line.propertiesForm.empty()) {
			for (uint32_t i = 0; i < line.propertiesForm.size(); i++) {
				RE::BGSMod::Attachment::Mod::Data data;
				curobj->GetData(data);

				for (uint32_t j = 0; j < data.propertyModCount; j++) {
					auto& mod = data.propertyMods[j];
					auto type = mod.type;

					switch (type) {
					case RE::BGSMod::Property::TYPE::kInt:
						//logger::debug(FMT_STRING("OMOD Data Type {} kInt {} {} | {} {}"), std::to_string(mod.target), mod.data.mm.min.i, mod.data.mm.max.i, mod.data.mm.min.f, mod.data.mm.max.f);
						break;
					case RE::BGSMod::Property::TYPE::kFloat:
						break;
					case RE::BGSMod::Property::TYPE::kBool:
						//logger::debug(FMT_STRING("OMOD Data Editor ID {:08X}"), mod.data.fv.formID);
						break;
					case RE::BGSMod::Property::TYPE::kString:
						break;
					case RE::BGSMod::Property::TYPE::kForm:
						if (mod.data.mm.min.i != 0) {
							RE::TESForm* currentform = GetFormFromIdentifier(line.propertiesForm[i]);
							RE::TESForm* currentformValue = GetFormFromIdentifier(line.propertiesFormValues[i]);
							if (currentform && currentformValue && mod.data.form->formID == currentform->formID) {
								mod.data.form = currentformValue;
								logger::debug(FMT_STRING("omod {:08X} {} changed form {:08X} to {:08X}"), curobj->formID, curobj->fullName, currentform->formID, currentformValue->formID);
							}
						}
						break;
					case RE::BGSMod::Property::TYPE::kEnum:
						break;
					case RE::BGSMod::Property::TYPE::kPair:

						break;
					}
				}
			}
		}

		if (!line.propertiesToRemoveForm.empty()) {
			for (uint32_t i = 0; i < line.propertiesToRemoveForm.size(); i++) {
				int propertyId = getPropertyFromString(line.propertiesToRemoveForm[i]);
				RE::BGSMod::Attachment::Mod::Data data;
				curobj->GetData(data);

				for (uint32_t j = 0; j < data.propertyModCount; j++) {
					auto& mod = data.propertyMods[j];
					
					auto type = mod.type;
					
					switch (type) {
					case RE::BGSMod::Property::TYPE::kForm:
						if (mod.data.mm.min.i != 0) {
							RE::TESForm* currentform = GetFormFromIdentifier(line.propertiesToRemoveForm[i]);
							if (currentform && mod.data.form->formID == currentform->formID) {
								mod.RemoveData();
								logger::debug(FMT_STRING("omod {:08X} {} Removed form {:08X}"), curobj->formID, curobj->fullName, currentform->formID);
							}
						}
						break;
					}
				}
			}
		}

		if (!line.propertiesToRemovePV.empty()) {
			for (uint32_t i = 0; i < line.propertiesToRemovePV.size(); i++) {
				int propertyId = getPropertyFromString(line.propertiesToRemovePV[i]);
				RE::BGSMod::Attachment::Mod::Data data;
				curobj->GetData(data);

				for (uint32_t j = 0; j < data.propertyModCount; j++) {
					RE::BGSMod::Property::Mod& mod = data.propertyMods[j];
					auto type = mod.type;
					switch (type) {
					case RE::BGSMod::Property::TYPE::kPair:
						RE::TESForm* currentform = GetFormFromIdentifier(line.propertiesToRemovePV[i]);
						if (currentform && mod.data.fv.formID == currentform->formID) {
							mod.RemoveData();
							logger::debug(FMT_STRING("omod {:08X} {} Removed value pair {:08X}"), curobj->formID, curobj->fullName, currentform->formID);
						}
						break;
					}
				}
			}
		}
		if (!line.propertiesToRemove.empty()) {
			for (uint32_t i = 0; i < line.propertiesToRemove.size(); i++) {
				int propertyId = getPropertyFromString(line.propertiesToRemove[i]);
				RE::BGSMod::Attachment::Mod::Data data;
				curobj->GetData(data);

				for (uint32_t j = 0; j < data.propertyModCount; j++) {
					auto& mod = data.propertyMods[j];
					auto type = mod.type;

					if (propertyId == mod.target) {
						logger::debug(FMT_STRING("omod {:08X} {} removed property {}"), curobj->formID, curobj->fullName, line.propertiesToRemove[i]);
						mod.RemoveData();
					}
				}
			}
		}

		/* if (!line.propertiesToAdd.empty()) {
			//RE::MemoryManager& mm = RE::MemoryManager::GetSingleton();
			for (uint32_t i = 0; i < line.propertiesToAdd.size(); i++) {
				int propertyId = getPropertyFromString(line.propertiesToAdd[i]);

				RE::BGSMod::Attachment::Mod::Data data;
				//RE::BGSMod::Attachment::Mod::Data data2;
				curobj->GetData(data);
				
				RE::BGSMod::Property::Mod* newPropertyMods = new RE::BGSMod::Property::Mod[data.propertyModCount + 1];
				//logger::debug(FMT_STRING("omod added {:08X} target {} "), curobj->formID, (int)data.propertyMods[data.propertyModCount-1].target);
				if (data.propertyMods != nullptr) {
					for (int i = 0; i < data.propertyModCount; i++) {
						logger::debug(FMT_STRING("omod before adding {:08X} target {} max size {}"), curobj->formID, (int)data.propertyMods[i].target, data.propertyModCount);
						newPropertyMods[i].type = data.propertyMods[i].type;
						newPropertyMods[i].target = data.propertyMods[i].target;
						newPropertyMods[i].step = data.propertyMods[i].step;
						newPropertyMods[i].op = data.propertyMods[i].op;
						newPropertyMods[i].data.form = data.propertyMods[i].data.form;
						newPropertyMods[i].data.fv.formID = data.propertyMods[i].data.fv.formID;
						newPropertyMods[i].data.fv.value = data.propertyMods[i].data.fv.value;
						newPropertyMods[i].data.mm.min.f = data.propertyMods[i].data.mm.min.f;
						newPropertyMods[i].data.mm.min.i = data.propertyMods[i].data.mm.min.i;
						newPropertyMods[i].data.mm.max.f = data.propertyMods[i].data.mm.max.f;
						newPropertyMods[i].data.mm.max.i = data.propertyMods[i].data.mm.max.i;
						
						if (data.propertyMods[i].target == 28) {
							//if (data.propertyMods[i].data.form)
							//	logger::debug(FMT_STRING("omod before adding {:08X} form {:08x}"), curobj->formID, data.propertyMods[i].data.form->formID);
							if (data.propertyMods[i].data.form)
								logger::debug(FMT_STRING("omod before adding {:08X} fv f {:08x}"), curobj->formID, data.propertyMods[i].data.fv.formID);
							logger::debug(FMT_STRING("omod before adding {:08X} fv va {}"), curobj->formID, data.propertyMods[i].data.fv.value);
							logger::debug(FMT_STRING("omod before adding {:08X} data.mm.min {}"), curobj->formID, data.propertyMods[i].data.mm.min.f);
							logger::debug(FMT_STRING("omod before adding {:08X} data.mm.min {}"), curobj->formID, data.propertyMods[i].data.mm.min.i);
							logger::debug(FMT_STRING("omod before adding {:08X} data.mm.max {}"), curobj->formID, data.propertyMods[i].data.mm.max.f);
							logger::debug(FMT_STRING("omod before adding {:08X} data.mm.max {}"), curobj->formID, data.propertyMods[i].data.mm.max.i);

							//logger::debug(FMT_STRING("omod before adding {:08X} a count {}"), curobj->formID, data.attachmentCount);
							//logger::debug(FMT_STRING("omod before adding {:08X} data.mm.max {}"), curobj->formID, data.attachments[i].mod->formID);
							//logger::debug(FMT_STRING("omod before adding {:08X} data.mm.max {}"), curobj->formID, data.attachments[i].index);

							//if (!data.propertyMods[i].data.str.empty() )
							//	logger::debug(FMT_STRING("omod before adding {:08X} target {}"), curobj->formID, data.propertyMods[i].data.str.c_str());
							newPropertyMods[i].data.mm.min.f = 100.0f;
							//logger::debug(FMT_STRING("omod before adding {:08X} data.mm.min {}"), curobj->formID, data.propertyMods[i].data.mm.min.f);
						}
					}
				}

				//newPropertyMods[data.propertyModCount].type = RE::BGSMod::Property::TYPE::kFloat;
				//newPropertyMods[data.propertyModCount].target = (uint32_t)28;
				//newPropertyMods[data.propertyModCount].op = RE::BGSMod::Property::OP::kMul;
				//newPropertyMods[data.propertyModCount].data.mm.min.f = 99.0;
				//newPropertyMods[data.propertyModCount].data.mm.max.f = 99.0;
				//newPropertyMods[data.propertyModCount].data.mm.min.i = 0;
				//newPropertyMods[data.propertyModCount].data.mm.max.i = 0;
				//newPropertyMods[data.propertyModCount].step = 0;
				//newPropertyMods[data.propertyModCount].step = 0;
				//data.propertyModCount++;
				data.propertyMods = newPropertyMods;

				for (int i = 0; i < data.propertyModCount; i++) {
					logger::debug(FMT_STRING("omod after adding {:08X} target {} max size {} {}"), curobj->formID, (int)data.propertyMods[i].target, data.propertyModCount, data.propertyMods[i].data.mm.min.f);
				}
				curobj->ClearData();
				curobj->SetDataN(&data);
				//RE::BGSMod::Attachment::Mod::Data data;
				//curobj->GetData(data);
				//RE::BGSMod::Property::Mod* newPropertyMods = new RE::BGSMod::Property::Mod[data.propertyModCount+1];
				////logger::debug(FMT_STRING("omod added {:08X} target {} "), curobj->formID, (int)data.propertyMods[data.propertyModCount-1].target);
				//if (data.propertyMods != nullptr) {
				//	for (int i = 0; i < data.propertyModCount; i++) {
				//		/*if (data.propertyMods[i].data.str.c_str()) {
				//		logger::debug(FMT_STRING("omod added {:08X} target {} str {}"), curobj->formID, (int)data.propertyMods[i].target, data.propertyMods[i].data.str.c_str());
				//		} else {
				//		}*/
				//		logger::debug(FMT_STRING("omod before adding {:08X} target {} max size{}"), curobj->formID, (int)data.propertyMods[i].target, data.propertyModCount);
				//		newPropertyMods[i].type = data.propertyMods[i].type;
				//		newPropertyMods[i].target = data.propertyMods[i].target;
				//		newPropertyMods[i].step = data.propertyMods[i].step;
				//		newPropertyMods[i].op = data.propertyMods[i].op;
				//		newPropertyMods[i].data.form = data.propertyMods[i].data.form;
				//		newPropertyMods[i].data.fv.formID = data.propertyMods[i].data.fv.formID;
				//		newPropertyMods[i].data.fv.value = data.propertyMods[i].data.fv.value;
				//		newPropertyMods[i].data.mm.min.f = data.propertyMods[i].data.mm.min.f;
				//		newPropertyMods[i].data.mm.min.i = data.propertyMods[i].data.mm.min.i;
				//		newPropertyMods[i].data.mm.max.f = data.propertyMods[i].data.mm.max.f;
				//		newPropertyMods[i].data.mm.max.i = data.propertyMods[i].data.mm.max.i;
				//		
				//		if (data.propertyMods[i].target == 28) {
				//			//if (data.propertyMods[i].data.form)
				//			//	logger::debug(FMT_STRING("omod before adding {:08X} form {:08x}"), curobj->formID, data.propertyMods[i].data.form->formID);
				//			if (data.propertyMods[i].data.form)
				//				logger::debug(FMT_STRING("omod before adding {:08X} fv f {:08x}"), curobj->formID, data.propertyMods[i].data.fv.formID);
				//			logger::debug(FMT_STRING("omod before adding {:08X} fv va {}"), curobj->formID, data.propertyMods[i].data.fv.value);
				//			logger::debug(FMT_STRING("omod before adding {:08X} data.mm.min {}"), curobj->formID, data.propertyMods[i].data.mm.min.f);
				//			logger::debug(FMT_STRING("omod before adding {:08X} data.mm.min {}"), curobj->formID, data.propertyMods[i].data.mm.min.i);
				//			logger::debug(FMT_STRING("omod before adding {:08X} data.mm.max {}"), curobj->formID, data.propertyMods[i].data.mm.max.f);
				//			logger::debug(FMT_STRING("omod before adding {:08X} data.mm.max {}"), curobj->formID, data.propertyMods[i].data.mm.max.i);
				//			//if (!data.propertyMods[i].data.str.empty() )
				//			//	logger::debug(FMT_STRING("omod before adding {:08X} target {}"), curobj->formID, data.propertyMods[i].data.str.c_str());
				//			newPropertyMods[i].data.mm.min.f = 100;
				//			logger::debug(FMT_STRING("omod before adding {:08X} data.mm.min {}"), curobj->formID, data.propertyMods[i].data.mm.min.f);
				//		}

				//	}
				//}

				//newPropertyMods[data.propertyModCount].type = RE::BGSMod::Property::TYPE::kFloat;
				//newPropertyMods[data.propertyModCount].target = (uint32_t)28;
				//newPropertyMods[data.propertyModCount].op = RE::BGSMod::Property::OP::kAdd;
				//newPropertyMods[data.propertyModCount].data.mm.min.f = 99.0;
				//newPropertyMods[data.propertyModCount].data.mm.max.f = 99.0;
				//newPropertyMods[data.propertyModCount].data.mm.min.i = 0;
				//newPropertyMods[data.propertyModCount].data.mm.max.i = 0;
				//newPropertyMods[data.propertyModCount].step = 0;

				//data.propertyMods = newPropertyMods;
				////data.propertyModCount++;
				//if (data.propertyMods != nullptr) {
				//	for (int i = 0; i < data.propertyModCount; i++) {
				//		logger::debug(FMT_STRING("omod after adding {:08X} target {} maxsize {}"), curobj->formID, (int)data.propertyMods[i].target, data.propertyModCount);
				//	}
				//}
				//curobj->SetData(data);
				//if (data.propertyMods != nullptr) {
				//	std::memcpy(newPropertyMods, data.propertyMods, data.propertyModCount * sizeof(RE::BGSMod::Property::Mod));
				//}
				//newPropertyMods[data.propertyModCount-1].type = RE::BGSMod::Property::TYPE::kFloat;
				//newPropertyMods[data.propertyModCount-1].target = 28;
				//newPropertyMods[data.propertyModCount-1].op = RE::BGSMod::Property::OP::kAdd;
				//newPropertyMods[data.propertyModCount-1].data.mm.min.f = 99.0;
				//newPropertyMods[data.propertyModCount-1].step = 0;
	//		}
		//}

		if (!line.fullName.empty() && line.fullName != "none") {
			try {
				logger::debug(FMT_STRING("omod formid: {:08X} {} changed fullname to {}"), curobj->formID, curobj->fullName, line.fullName);
				curobj->fullName = line.fullName;
			} catch (const std::invalid_argument& e) {
			}
		}
	
		if (!line.functionTypeProperties.empty() ) {
			for (uint32_t i = 0; i < line.functionTypeProperties.size(); i++) {
				std::string lowercaseFunctionType = line.functionTypeProperties[i];
				std::transform(lowercaseFunctionType.begin(), lowercaseFunctionType.end(), lowercaseFunctionType.begin(), [](unsigned char c) { return std::tolower(c); });
				std::string lowercaseFunctionTypeValues = line.functionTypeValues[i];
				std::transform(lowercaseFunctionTypeValues.begin(), lowercaseFunctionTypeValues.end(), lowercaseFunctionTypeValues.begin(), [](unsigned char c) { return std::tolower(c); });
				RE::BGSMod::Attachment::Mod::Data data;
				curobj->GetData(data);
				int propertyId = getPropertyFromString(lowercaseFunctionType);

				for (uint32_t j = 0; j < data.propertyModCount; j++) {
					auto& mod = data.propertyMods[j];
					auto type = mod.type;

					if (propertyId == mod.target) {
						//logger::debug(FMT_STRING("omod {:08X} {} removed property {}"), curobj->formID, curobj->fullName, line.propertiesToRemove[i]);
						if (lowercaseFunctionTypeValues == "add") {
							mod.op = RE::BGSMod::Property::OP::kAdd;
							logger::debug(FMT_STRING("omod {:08X} {} changed function type of {} to ADD "), curobj->formID, curobj->fullName, lowercaseFunctionType);
						} else if (lowercaseFunctionTypeValues == "set") {
							mod.op = RE::BGSMod::Property::OP::kSet;
							logger::debug(FMT_STRING("omod {:08X} {} changed function type of {} to SET "), curobj->formID, curobj->fullName, lowercaseFunctionType);
						} else if (lowercaseFunctionTypeValues == "multandadd") {
							mod.op = RE::BGSMod::Property::OP::kMul;
							logger::debug(FMT_STRING("omod {:08X} {} changed function type of {} to MULT+ADD"), curobj->formID, curobj->fullName, lowercaseFunctionType);
						} else if ( lowercaseFunctionTypeValues == "rem") {
							mod.op = RE::BGSMod::Property::OP::kRem;
							logger::debug(FMT_STRING("omod {:08X} {} changed function type of {} to REM "), curobj->formID, curobj->fullName, lowercaseFunctionType);
						}
					}
				}



				//logger::debug(FMT_STRING("weapon formid: {:08X} {} changed weight {}"), curobj->formID);
			}
		}

		if (!line.attachParentSlotKeywordsToAdd.empty()) {
			//logger::debug("-requiered for whatever reason- 1");
			for (size_t i = 0; i < line.attachParentSlotKeywordsToAdd.size(); i++) {
				//logger::debug("-requiered for whatever reason- 2");
				RE::TESForm* currentform = nullptr;
				std::string string_form = line.attachParentSlotKeywordsToAdd[i];
				currentform = GetFormFromIdentifier(string_form);
				//logger::debug("-requiered for whatever reason- {}", string_form);
				if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
					//logger::debug("-requiered for whatever reason- 3");
					if (curobj->attachParents.HasKeyword2((RE::BGSKeyword*)currentform)) {
					} else {
						//logger::debug("-requiered for whatever reason- 4");
						curobj->attachParents.AddKeyword((RE::BGSKeyword*)currentform);
						logger::debug(FMT_STRING("omod formid: {:08X} {} added attach parent slot keyword {:08X} {} "), curobj->formID, curobj->fullName, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
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
					if (!curobj->attachParents.HasKeyword2((RE::BGSKeyword*)currentform)) {
						curobj->attachParents.RemoveKeyword((RE::BGSKeyword*)currentform);

						logger::debug(FMT_STRING("omod formid: {:08X} removed attach parent slot keyword {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
					}
				}
			}
		}

		if (!line.attachPoint.empty() && line.attachPoint != "none") {
			RE::TESForm* currentform = nullptr;
			std::string string_form = line.attachPoint;
			currentform = GetFormFromIdentifier(string_form);
			if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
				curobj->attachPoint.keywordIndex = BGSKeywordGetIndexForTypedKeyword( ((RE::BGSKeyword*)currentform), RE::KeywordType::kAttachPoint );
				logger::debug(FMT_STRING("omod formid: {:08X} changed attachPoint to {:08X} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID);
			} else if (line.attachPoint == "null") {
				curobj->attachPoint.keywordIndex = 0;
				logger::debug(FMT_STRING("omod formid: {:08X} changed attachPoint to null (none) "), curobj->formID);
			}
		}

		//if (!line.keywordsToAdd.empty()) {
		//	for (size_t i = 0; i < line.keywordsToAdd.size(); i++) {
		//		RE::TESForm* currentform = nullptr;
		//		std::string string_form = line.keywordsToAdd[i];
		//		currentform = GetFormFromIdentifier(string_form);
		//		if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
		//			
		//			logger::debug(FMT_STRING("omod formid: {:08X} {} keywordsize {} "), curobj->formID, curobj->fullName, curobj->filterKeywords.size);

		//			//if (curobj->filterKeywords.HasKeyword((RE::BGSKeyword*)currentform)) {
		//			//	logger::debug(FMT_STRING("omod formid: {:08X} {} added target keyword {:08X} {} "), curobj->formID, curobj->fullName, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
		//			//} else {
		//			//	logger::debug(FMT_STRING("omod formid: {:08X} {} has not added target keyword {:08X} {} "), curobj->formID, curobj->fullName, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);

		//			//}
		//		}
		//	}
		//}

		//if (!line.keywordsToRemove.empty()) {
		//	for (size_t i = 0; i < line.keywordsToRemove.size(); i++) {
		//		RE::TESForm* currentform = nullptr;
		//		std::string string_form = line.keywordsToRemove[i];
		//		currentform = GetFormFromIdentifier(string_form);
		//		if (currentform && currentform->formType == RE::ENUM_FORM_ID::kKYWD) {
		//			curobj->filterKeywords.RemoveKeywordModAssociation((RE::BGSKeyword*)currentform);
		//			logger::debug(FMT_STRING("omod formid: {:08X} removed target keyword {:08X} {} "), curobj->formID, ((RE::BGSKeyword*)currentform)->formID, ((RE::BGSKeyword*)currentform)->formEditorID);
		//		}
		//	}
		//}



	}

}

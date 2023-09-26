#include "utility.h"
#include <regex>
#include <unordered_map>
#include <string>


//void RemoveOModEntry(RE::BGSMod::Attachment::Mod::Data* a_modData, uint32_t property)
//{
//	int propertiesToRemove = 0;
//
//		if (a_modData) {
//		RE::MemoryManager& mm = RE::MemoryManager::GetSingleton();
//		for (uint32_t i = 0; i < a_modData->propertyModCount; i++) {
//			auto& mod = a_modData->propertyMods[i];
//
//			if (mod.target == property) {
//				++propertiesToRemove;
//				logger::debug(FMT_STRING("propertiesToRemove {}"), propertiesToRemove);
//			}
//		}
//		logger::debug(FMT_STRING("property count {} propertiesToRemove {}"), a_modData->propertyModCount, propertiesToRemove);
//		if (a_modData->propertyModCount > 0 && propertiesToRemove > 0) {
//			auto test = a_modData->propertyMods;
//			RE::BGSMod::Property::Mod* newArray = (RE::BGSMod::Property::Mod*)mm.Allocate(sizeof(RE::BGSMod::Property::Mod*) * (a_modData->propertyModCount - propertiesToRemove), 0, false);
//			for (int i = 0, j = 0; i < a_modData->propertyModCount; ++i) {
//				const auto& kywd = a_modData->propertyMods[i];
//				if (kywd.target != property) {
//					std::memcpy(&newArray[j], &a_modData->propertyMods[i], sizeof(RE::BGSMod::Property::Mod));
//					++j;
//					logger::debug(FMT_STRING("j {}"), j);
//				}
//			}
//			mm.Deallocate(a_modData->propertyMods, false);
//
//			a_modData->propertyMods = newArray;
//			a_modData->propertyModCount - propertiesToRemove;
//		} else {
//			mm.Deallocate(a_modData->propertyMods, false);
//			a_modData->propertyMods = nullptr;
//			a_modData->propertyModCount = 0;
//		}
//	}
//}





uint32_t getPropertyFromString(std::string text)
{
	// Convert input text to lowercase
	std::transform(text.begin(), text.end(), text.begin(), ::tolower);

	// Define a hash map to map string values to integer values
	static const std::unordered_map<std::string, uint32_t> propertyMap = {
		{ "speed", 0 },
		{ "minrange", 2 },
		{ "maxrange", 3 },
		{ "attackdelaysec", 4 },
		{ "secondarydamage", 7 },
		{ "attackdamage", 28 },
		{ "value", 29 },
		{ "weight", 30 },
		{ "keywords", 31 },
		{ "aimmodelminconedegrees", 33 },
		{ "aimmodelmaxconedegrees", 34 },
		{ "aimmodelrecoilmaxdegpershot", 41 },
		{ "aimmodelrecoilmindegpershot", 42 },
		{ "aimmodelrecoilshotsforrunaway", 44 },
		{ "aimmodelconeironsightsmultiplier", 47 },
		{ "soundlevel", 59 },
		{ "ammo", 61 },
		{ "enchantments", 65 },
		{ "npcammolist", 75 },
		{ "damagetypevalues", 77 },
		{ "attackactionpointcost", 79 },
		{ "overrideprojectile", 80 },
		{ "sightedtransitionseconds", 83 },
		{ "colorremappingindex", 88 },
		{ "actorvalues", 94 }
	};

	// Look up the input text in the hash map
	auto it = propertyMap.find(text);
	if (it != propertyMap.end()) {
		return it->second;
	} else {
		return -1;
	}
}


template <typename T>
T GetOffset(const void* baseObject, int offset)
{
	return *reinterpret_cast<T*>((uintptr_t)baseObject + offset);
}

RE::TESForm* GetFormFromIdentifier(const std::string& identifier)
{
	auto dataHandler = RE::TESDataHandler::GetSingleton();
	auto delimiter = identifier.find('|');
	if (delimiter != std::string::npos) {
		std::string modName = identifier.substr(0, delimiter);
		std::string modForm = identifier.substr(delimiter + 1);

		auto* mod = dataHandler->LookupModByName(modName.c_str());
		if (mod && mod->compileIndex != -1) {
			uint32_t formID = std::stoul(modForm, nullptr, 16) & 0xFFFFFF;
			uint32_t flags = GetOffset<uint32_t>(mod, 0x334);
			if (flags & (1 << 9)) {
				// ESL
				formID &= 0xFFF;
				formID |= 0xFE << 24;
				formID |= GetOffset<uint16_t>(mod, 0x372) << 12;  // ESL load order
			} else {
				formID |= (mod->compileIndex) << 24;
			}
			return RE::TESForm::GetFormByID(formID);
		}
	}
	return nullptr;
}

	bool IsPluginInstalled(const char* name)
{
	auto dataHandler = RE::TESDataHandler::GetSingleton();
	auto* modInfo = dataHandler->LookupLoadedModByName(name);
	if (modInfo)
		return true;

	modInfo = dataHandler->LookupLoadedLightModByName(name);
	if (modInfo)
		return true;

	return false;
}

	
int findPositionInArray(RE::BSTArray<RE::TESForm*> pArray, RE::TESForm* form)
{
	if (pArray.empty() || !form) {
		return -1;
	}

	for (size_t i = 0; i < pArray.size(); i++) {
		if (pArray[i] == form) {
			return i;
		}
	}

	return -1;
}



bool changeAVIF_NPC(RE::TESNPC* pNPC, RE::ActorValueInfo* pActorValueInfo, float pfValue)
{
	if (pNPC->properties) {
		for (size_t i = 0; i < pNPC->properties->size(); i++) {
			if (pNPC->properties[0][i].first->formID == pActorValueInfo->formID) {
				pNPC->properties[0][i].second.f = pfValue;
				//logger::info("avif changed!");
				return true;
			}
		}
	} else {
		pNPC->properties = new RE::BSTArray<RE::BSTTuple<RE::TESForm*, RE::BGSTypedFormValuePair::SharedVal>>;
	}
	RE::BSTTuple<RE::TESForm*, RE::BGSTypedFormValuePair::SharedVal> newTuple;
	newTuple.first = pActorValueInfo;
	newTuple.second.f = pfValue;
	pNPC->properties[0].push_back(newTuple);
	//logger::info("avif added!");
	return true;
}

bool changeAVIF_Race(RE::TESRace* pNPC, RE::ActorValueInfo* pActorValueInfo, float pfValue)
{
	if (pNPC->properties) {
	for (size_t i = 0; i < pNPC->properties->size(); i++) {
		if (pNPC->properties[0][i].first->formID == pActorValueInfo->formID) {
			pNPC->properties[0][i].second.f = pfValue;
			//logger::info("avif changed!");
			return true;
		}
	}
	} else {
		pNPC->properties = new RE::BSTArray<RE::BSTTuple<RE::TESForm*, RE::BGSTypedFormValuePair::SharedVal>>;
	}
	RE::BSTTuple<RE::TESForm*, RE::BGSTypedFormValuePair::SharedVal> newTuple;
	newTuple.first = pActorValueInfo;
	newTuple.second.f = pfValue;
	pNPC->properties[0].push_back(newTuple);
	//logger::info("avif added!");
	return true;
}

RE::EffectItem* createNewEffectItem(RE::EffectItem* item, RE::EffectSetting* setting, float magni, int dur, int area) {

	using func_t = decltype(&createNewEffectItem);
	REL::Relocation<func_t> func{ REL::ID(1219158) };
	return func(item, setting, magni, dur, area);


}

bool changeKeyword_TESLevItem(RE::TESLevItem* pNPC, RE::BGSKeyword* pActorValueInfo, float pfValue)
{
	if (pNPC->keywordChances) {
		for (size_t i = 0; i < pNPC->keywordChances->size(); i++) {
		if (pNPC->keywordChances[0][i].first->formID == pActorValueInfo->formID) {
			pNPC->keywordChances[0][i].second.f = pfValue;
			//logger::info("avif changed!");
			return true;
		}
		}
	} else {
		pNPC->keywordChances = new RE::BSTArray<RE::BSTTuple<RE::TESForm*, RE::BGSTypedFormValuePair::SharedVal>>;
	}
	RE::BSTTuple<RE::TESForm*, RE::BGSTypedFormValuePair::SharedVal> newTuple;
	newTuple.first = pActorValueInfo;
	newTuple.second.i = static_cast<uint32_t>(pfValue);
	pNPC->keywordChances[0].push_back(newTuple);
	//logger::info("avif added!");
	return true;
}

bool changeDamageType_Weapon(RE::TESObjectWEAP* object, RE::BGSDamageType* type, float pfValue)
{
	if (object->weaponData.damageTypes) {
		for (size_t i = 0; i < object->weaponData.damageTypes->size(); i++) {
			if (object->weaponData.damageTypes[0][i].first->formID == type->formID) {
				object->weaponData.damageTypes[0][i].second.i = static_cast<uint32_t>(pfValue);
				return true;
			}
		}
	} else {
		object->weaponData.damageTypes = new RE::BSTArray<RE::BSTTuple<RE::TESForm*, RE::BGSTypedFormValuePair::SharedVal>> ;
	}
	RE::BSTTuple<RE::TESForm*, RE::BGSTypedFormValuePair::SharedVal> newTuple;
	newTuple.first = type;
	newTuple.second.i = static_cast<uint32_t>(pfValue);

	object->weaponData.damageTypes[0].push_back(newTuple);
	return true;
}

bool eraseDamageType_Weapon(RE::TESObjectWEAP* object, RE::BGSDamageType* type)
{
	if (object->weaponData.damageTypes->size() > 0 && object->weaponData.damageTypes[0].size() > 0) {
	
    // Assuming object->weaponData.damageTypes is your vector
		auto& damageTypes = object->weaponData.damageTypes[0];
		int formIDToMatch = type->formID;  // The formID you want to match

		// Use std::remove_if and std::erase to remove elements based on the condition
		damageTypes.erase(
			std::remove_if(
				damageTypes.begin(),
				damageTypes.end(),
				[&](const RE::BSTTuple<RE::TESForm*, RE::BGSTypedFormValuePair::SharedVal>& type) {
					return type.first->formID == formIDToMatch;
				}),
			damageTypes.end());

		return true;
	}
	return false;
}

bool changeDamageType_Armor(RE::TESObjectARMO* object, RE::BGSDamageType* type, float pfValue)
{
	if (object->armorData.damageTypes) {
		for (size_t i = 0; i < object->armorData.damageTypes->size(); i++) {
			if (object->armorData.damageTypes[0][i].first->formID == type->formID) {
				object->armorData.damageTypes[0][i].second.i = static_cast<uint32_t>(pfValue);
				return true;
			}
		}
	} else {
		object->armorData.damageTypes = new RE::BSTArray<RE::BSTTuple<RE::TESForm*, RE::BGSTypedFormValuePair::SharedVal>>;
	}
	RE::BSTTuple<RE::TESForm*, RE::BGSTypedFormValuePair::SharedVal> newTuple;
	newTuple.first = type;
	//newTuple.second.f = pfValue;
	newTuple.second.i = static_cast<uint32_t>(pfValue);

	object->armorData.damageTypes[0].push_back(newTuple);

	return true;
}

//Misc Items

bool hasMISC_Item(RE::TESObjectMISC* pMisc, RE::BGSComponent* component)
{


}

bool changeMISC_Item(RE::TESObjectMISC* pMisc, RE::BGSComponent* component, float pfValue)
{
	if (pMisc->componentData) {
		for (size_t i = 0; i < pMisc->componentData->size(); i++) {
			if (pMisc->componentData[0][i].first->formID == component->formID) {
				pMisc->componentData[0][i].second.f = pfValue;
				//logger::info("avif changed!");
				return true;
			}
		}
	} else {
		pMisc->componentData = new RE::BSTArray<RE::BSTTuple<RE::TESForm*, RE::BGSTypedFormValuePair::SharedVal>>;
	}
	RE::BSTTuple<RE::TESForm*, RE::BGSTypedFormValuePair::SharedVal> newTuple;
	newTuple.first = component;
	newTuple.second.f = pfValue;
	pMisc->componentData[0].push_back(newTuple);
	//logger::info("avif added!");
	return true;
}


//template <typename T>
//T* getForm(std::string form) {
//
//	RE::TESForm* currentform = nullptr;
//	currentform = GetFormFromIdentifier(form);
//
//	if (currentform) {
//		return currentform->As<T*>();
//	}
//	return nullptr;
//}

std::string to_string(RE::BIPED_MODEL::BipedObjectSlot slot)
{
	switch (slot) {
	case RE::BIPED_MODEL::BipedObjectSlot::kNone:
		return "None";
	case RE::BIPED_MODEL::BipedObjectSlot::kHairTop:
		return "HairTop";
	case RE::BIPED_MODEL::BipedObjectSlot::kHairlong:
		return "Hairlong";
	case RE::BIPED_MODEL::BipedObjectSlot::kBodyFaceGenHead:
		return "BodyFaceGenHead";
	case RE::BIPED_MODEL::BipedObjectSlot::kBody:
		return "Body";
	case RE::BIPED_MODEL::BipedObjectSlot::kLleftHand:
		return "LleftHand";
	case RE::BIPED_MODEL::BipedObjectSlot::kRightHand:
		return "RightHand";
	case RE::BIPED_MODEL::BipedObjectSlot::kUTorso:
		return "UTorso";
	case RE::BIPED_MODEL::BipedObjectSlot::kULeftArm:
		return "ULeftArm";
	case RE::BIPED_MODEL::BipedObjectSlot::kURrightArm:
		return "URrightArm";
	case RE::BIPED_MODEL::BipedObjectSlot::kULeftLeg:
		return "ULeftLeg";
	case RE::BIPED_MODEL::BipedObjectSlot::kURirghtLeg:
		return "URirghtLeg";
	case RE::BIPED_MODEL::BipedObjectSlot::kATorso:
		return "ATorso";
	case RE::BIPED_MODEL::BipedObjectSlot::kALeftArm:
		return "ALeftArm";
	case RE::BIPED_MODEL::BipedObjectSlot::kARrightArm:
		return "ARrightArm";
	case RE::BIPED_MODEL::BipedObjectSlot::kALeftLeg:
		return "ALeftLeg";
	case RE::BIPED_MODEL::BipedObjectSlot::kARightLeg:
		return "ARightLeg";
	case RE::BIPED_MODEL::BipedObjectSlot::kHeadband:
		return "Headband";
	case RE::BIPED_MODEL::BipedObjectSlot::kEyes:
		return "Eyes";
	case RE::BIPED_MODEL::BipedObjectSlot::kBeard:
		return "Beard";
	case RE::BIPED_MODEL::BipedObjectSlot::kMouth:
		return "Mouth";
	case RE::BIPED_MODEL::BipedObjectSlot::kNeck:
		return "Neck";
	case RE::BIPED_MODEL::BipedObjectSlot::kRing:
		return "Ring";
	case RE::BIPED_MODEL::BipedObjectSlot::kScalp:
		return "Scalp";
	case RE::BIPED_MODEL::BipedObjectSlot::kDecapitation:
		return "Decapitation";
	case RE::BIPED_MODEL::BipedObjectSlot::kUnnamed1:
		return "Unnamed1";
	case RE::BIPED_MODEL::BipedObjectSlot::kUnnamed2:
		return "Unnamed2";
	case RE::BIPED_MODEL::BipedObjectSlot::kUnnamed3:
		return "Unnamed3";
	case RE::BIPED_MODEL::BipedObjectSlot::kUnnamed4:
		return "Unnamed4";
	case RE::BIPED_MODEL::BipedObjectSlot::kUnnamed5:
		return "Unnamed5";
	case RE::BIPED_MODEL::BipedObjectSlot::kShield:
		return "Shield";
	case RE::BIPED_MODEL::BipedObjectSlot::kPipboy:
		return "Pipboy";
	case RE::BIPED_MODEL::BipedObjectSlot::kFX01:
		return "FX01";
	default:
		return "Unknown";
	}
}

RE::BIPED_MODEL::BipedObjectSlot getBipedObjectSlot(int slot)
{
	switch (slot) {
	case 0:
		return RE::BIPED_MODEL::BipedObjectSlot::kHairTop;
	case 1:
		return RE::BIPED_MODEL::BipedObjectSlot::kHairlong;
	case 2:
		return RE::BIPED_MODEL::BipedObjectSlot::kBodyFaceGenHead;
	case 3:
		return RE::BIPED_MODEL::BipedObjectSlot::kBody;
	case 4:
		return RE::BIPED_MODEL::BipedObjectSlot::kLleftHand;
	case 5:
		return RE::BIPED_MODEL::BipedObjectSlot::kRightHand;
	case 6:
		return RE::BIPED_MODEL::BipedObjectSlot::kUTorso;
	case 7:
		return RE::BIPED_MODEL::BipedObjectSlot::kULeftArm;
	case 8:
		return RE::BIPED_MODEL::BipedObjectSlot::kURrightArm;
	case 9:
		return RE::BIPED_MODEL::BipedObjectSlot::kULeftLeg;
	case 10:
		return RE::BIPED_MODEL::BipedObjectSlot::kURirghtLeg;
	case 11:
		return RE::BIPED_MODEL::BipedObjectSlot::kATorso;
	case 12:
		return RE::BIPED_MODEL::BipedObjectSlot::kALeftArm;
	case 13:
		return RE::BIPED_MODEL::BipedObjectSlot::kARrightArm;
	case 14:
		return RE::BIPED_MODEL::BipedObjectSlot::kALeftLeg;
	case 15:
		return RE::BIPED_MODEL::BipedObjectSlot::kARightLeg;
	case 16:
		return RE::BIPED_MODEL::BipedObjectSlot::kHeadband;
	case 17:
		return RE::BIPED_MODEL::BipedObjectSlot::kEyes;
	case 18:
		return RE::BIPED_MODEL::BipedObjectSlot::kBeard;
	case 19:
		return RE::BIPED_MODEL::BipedObjectSlot::kMouth;
	case 20:
		return RE::BIPED_MODEL::BipedObjectSlot::kNeck;
	case 21:
		return RE::BIPED_MODEL::BipedObjectSlot::kRing;
	case 22:
		return RE::BIPED_MODEL::BipedObjectSlot::kScalp;
	case 23:
		return RE::BIPED_MODEL::BipedObjectSlot::kDecapitation;
	case 24:
		return RE::BIPED_MODEL::BipedObjectSlot::kUnnamed1;
	case 25:
		return RE::BIPED_MODEL::BipedObjectSlot::kUnnamed2;
	case 26:
		return RE::BIPED_MODEL::BipedObjectSlot::kUnnamed3;
	case 27:
		return RE::BIPED_MODEL::BipedObjectSlot::kUnnamed4;
	case 28:
		return RE::BIPED_MODEL::BipedObjectSlot::kUnnamed5;
	case 29:
		return RE::BIPED_MODEL::BipedObjectSlot::kShield;
	case 30:
		return RE::BIPED_MODEL::BipedObjectSlot::kPipboy;
	case 31:
		return RE::BIPED_MODEL::BipedObjectSlot::kFX01;
	default:
		return RE::BIPED_MODEL::BipedObjectSlot::kNone;
	}
}



std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first) {
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

std::vector<std::string> splitRelationNumber(const std::string& input)
{
	std::regex re(R"(([<>]=?|[<>])\s*(\d+))");
	std::smatch match;
	std::vector<std::string> result;

	if (std::regex_search(input, match, re)) {
		std::string relation_sign = match[1];
		std::string number_str = match[2];
		result.push_back(number_str);
		result.push_back(relation_sign);
	} else if (std::regex_search(input, std::regex(R"(\d+)"))) {
		result.push_back(input);
	} else {
		result.push_back("none");
	}

	return result;
}

std::string toLowerCase(std::string pString) {
	std::string lowercasepString = pString;
	std::transform(lowercasepString.begin(), lowercasepString.end(), lowercasepString.begin(), [](unsigned char c) { return std::tolower(c); });

	return lowercasepString;
}

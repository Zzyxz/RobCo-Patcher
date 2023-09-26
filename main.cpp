#include "dirent.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <gameforms.h>
#include <iostream>
#include <list>
#include <object_alch.h>
#include <object_ammos.h>
#include <object_armors.h>
#include <object_cobjs.h>
#include <object_formlist.h>
#include <object_leveledLists.h>
#include <object_misc.h>
#include <object_npcs.h>
#include <object_omod.h>
#include <object_races.h>
#include <object_weapons.h>
#include <regex>
#include <string>
#include <map>
#include <vector>
#include <algorithm>


using namespace std;

const char* configFile = ".\\Data\\F4se\\Plugins\\RobCo_Patcher.ini";
const char* settingsSection = "Patcher";
const char* settingsSectionLog = "Log";
const char* settingsSectionFeatures = "Features";

//typedef bool(_AddKeyword)(RE::TESNPC* actor, RE::BGSKeyword* keyword);
//REL::Relocation<_AddKeyword> AddKeywordInternal{ REL::ID(1024161) };
//1402D40 1011651
//1423910 1024161
//

//namespace createForms
//{

//void setBallisticWeaponsToZero()
//{
//	auto dataHandler = RE::TESDataHandler::GetSingleton();
//	logger::info("*********************************");
//	logger::info("Patching weapons...");
//	logger::info("*********************************");
//	RE::ActorValueInfo* AP = nullptr;
//	auto& weapons = dataHandler->GetFormArray<RE::TESObjectWEAP>();
//	//tArray<TESNPC*> npcs = (*g_dataHandler)->arrNPC_;
//	//tArray<TESAmmo*> ammos = (*g_dataHandler)->arrAMMO;
//	//TESObjectWEAP* currweap = nullptr;
//	//TESAmmo* currammo = nullptr;

//	//auto Ammo10mm = DYNAMIC_CAST(LookupFormByID(0x1f276), TESForm, TESAmmo);
//	//DumpClass(Ammo10mm, 0x1B0 / 8);
//	for (const auto& foundNPC : dataHandler->GetFormArray<RE::TESNPC>()) {
//	}
//	//readIni
//	/*constexpr char* configFile = ".\\Data\\F4se\\Plugins\\UnlimitedSurvivalMode.ini";
//	constexpr char* settingsSection = "Settings";
//	GetPrivateProfileInt(settingsSection, "iEnableFastTravel", 0, configFile);
//	*/

//	for (const auto& foundAmmo : dataHandler->GetFormArray<RE::TESAmmo>()) {
//		logger::debug(FMT_STRING("Name: {} | damage {}  "), foundAmmo->fullName.c_str(), foundAmmo->data.damage);
//	}

//	//_MESSAGE("1: %d | 2: %d", Ammo556->unk18, Ammo556->unk18);
//	//logger::info("count: %d", listRifle.count);
//	for (const auto& foundWeapon : dataHandler->GetFormArray<RE::TESObjectWEAP>()) {
//		//constexpr char* configFile = ".\\Data\\F4se\\Plugins\\UnlimitedSurvivalMode.ini";
//		//constexpr char* settingsSection = "Settings";
//		RE::TESObjectWEAP* currweap = foundWeapon;
//		//_MESSAGE("Weapon Found: %s ", currweap->fullName.name.c_str());

//		if (currweap && currweap->weaponData.ammo != nullptr && !currweap->HasKeyword(WeaponTypeLaser, 0) && !currweap->HasKeyword(WeaponTypeAlienBlaster, 0)) {
//			RE::TESForm* curammo = currweap->weaponData.ammo;
//			int ammoindex = -1;
//			if (currweap->HasKeyword(WeaponTypePistol, 0)) {
//				currweap->weaponData.attackDamage = 4;
//				currweap->weaponData.outOfRangeDamageMult = 0.75;
//				ammoindex = 0;
//				logger::debug(FMT_STRING("Weapon has keyword pistol: {} set Base Damage: {}"), currweap->fullName.c_str(), currweap->weaponData.attackDamage);
//			} else if (currweap->HasKeyword(WeaponTypeRifle, 0)) {
//				currweap->weaponData.attackDamage = 8;
//				currweap->weaponData.outOfRangeDamageMult = 0.75;
//				ammoindex = 0;
//				logger::debug(FMT_STRING("Weapon has keyword rifle: {} set Base Damage: {}"), currweap->fullName.c_str(), currweap->weaponData.attackDamage);
//			}

//			if (ammoindex == -1) {
//				ammoindex = findPositionInArray(listPistol, curammo);
//				if (ammoindex >= 0) {
//					currweap->weaponData.attackDamage = 4;
//					currweap->weaponData.outOfRangeDamageMult = 0.75;
//					logger::debug(FMT_STRING("Set weapon damage by ammo class: {} set Base Damage: {}"), currweap->fullName.c_str(), currweap->weaponData.attackDamage);
//				}
//			}
//			if (ammoindex == -1) {
//				ammoindex = findPositionInArray(listRifle, curammo);
//				if (ammoindex >= 0) {
//					currweap->weaponData.attackDamage = 8;
//					currweap->weaponData.outOfRangeDamageMult = 0.75;
//					logger::debug(FMT_STRING("Set weapon damage by ammo class: {} set Base Damage: {}"), currweap->fullName.c_str(), currweap->weaponData.attackDamage);
//				}
//			}
//		}
//	}
//}

//	void patchNPC()
//	{
//		//RE::BGSTypedFormValuePair::SharedVal newPair;
//		////newPair.i =
//		//RE::BSTTuple<RE::TESForm*, RE::BGSTypedFormValuePair::SharedVal> newTuple;
//		//auto playerProps = Player->properties[0];
//		//newTuple.first = Health;
//		//newTuple.second.f = 9999;
//		////newTuple.second.i = 0;
//		//playerProps.push_back(newTuple);
//		//Player->properties[0] = playerProps;
//		//RE::Actor* PlayerRef;
//
//		if (const auto dataHandler = RE::TESDataHandler::GetSingleton(); dataHandler) {
//			for (const auto& curNPC : dataHandler->GetFormArray<RE::TESNPC>()) {
//				if (curNPC) {
//					logger::info(FMT_STRING("-> formID {:08X}"), curNPC->formID);
//					if (curNPC->actorData.templateUseFlags & (RE::ACTOR_BASE_DATA::TEMPLATE_USE_FLAG::kStats)) {
//						logger::info(FMT_STRING("has Stats flag"));
//					} else {
//						logger::info(FMT_STRING("no Stats flag"));
//					}
//					auto properties = curNPC->properties;
//					logger::info(FMT_STRING("Value: {}"), properties->size());
//					for (size_t i = 0; i < properties->size(); i++) {
//						logger::info(FMT_STRING("FormID Value: {:08X}"), properties[0][i].first->formID);
//						logger::info(FMT_STRING("Value as Float: {}"), properties[0][i].second.f);
//					}
//				}
//			}
//		}
//	}
//}

namespace
{



	void MessageHandler(F4SE::MessagingInterface::Message* a_msg)
	{
		if (!a_msg) {
			return;
		}

		switch (a_msg->type) {
		case F4SE::MessagingInterface::kGameDataReady:
			{
				if (static_cast<bool>(a_msg->data)) {
					GAMEFORMS::DefineGameForms();

					

					if (GetPrivateProfileInt(settingsSection, "iEnableAmmoPatching", 0, configFile)) {
						AMMOS::readConfig(".\\Data\\F4se\\Plugins\\RobCo_Patcher\\ammo\\");
					}

					if (GetPrivateProfileInt(settingsSection, "iEnableWeaponPatching", 0, configFile)) {
						WEAPONS::readConfig(".\\Data\\F4se\\Plugins\\RobCo_Patcher\\weapon\\");
					}

					if (GetPrivateProfileInt(settingsSection, "iEnableRacePatching", 0, configFile)) {
						RACES::readConfig(".\\Data\\F4se\\Plugins\\RobCo_Patcher\\race\\");
					}

					if (GetPrivateProfileInt(settingsSection, "iEnableNPCPatching", 0, configFile)) {
						NPCS::readConfig(".\\Data\\F4se\\Plugins\\RobCo_Patcher\\npc");
					}



					if (GetPrivateProfileInt(settingsSection, "iEnableArmorPatching", 0, configFile)) {
						ARMORS::readConfig(".\\Data\\F4se\\Plugins\\RobCo_Patcher\\armor\\");
					}

					if (GetPrivateProfileInt(settingsSection, "iEnableFormlistPatching", 0, configFile)) {
						FORMLIST::readConfig(".\\Data\\F4se\\Plugins\\RobCo_Patcher\\formList\\");
					}

					if (GetPrivateProfileInt(settingsSection, "iEnableConstructibleObjectPatching", 0, configFile)) {
						COBJ::readConfig(".\\Data\\F4se\\Plugins\\RobCo_Patcher\\constructibleObject\\");
					}

					if (GetPrivateProfileInt(settingsSection, "iEnableLeveledListPatching", 0, configFile)) {
						LEVELEDLISTS::readConfig(".\\Data\\F4se\\Plugins\\RobCo_Patcher\\leveledList\\");
					}

					if (GetPrivateProfileInt(settingsSection, "iEnableObjectModificationPatching", 0, configFile)) {
						OMOD::readConfig(".\\Data\\F4se\\Plugins\\RobCo_Patcher\\objectModification\\");
					}

					if (GetPrivateProfileInt(settingsSection, "iEnableMiscPatching", 0, configFile)) {
						MISC::readConfig(".\\Data\\F4se\\Plugins\\RobCo_Patcher\\misc\\");
					}

					if (GetPrivateProfileInt(settingsSection, "iEnableIngestiblePatching", 0, configFile)) {
						ALCH::readConfig(".\\Data\\F4se\\Plugins\\RobCo_Patcher\\ingestible\\");
					}

					if (GetPrivateProfileInt(settingsSectionFeatures, "iEnableREFRCreateNewInstanceData", 0, configFile)) {
						//const auto dataHandler = RE::TESDataHandler::GetSingleton();
						////RE::BSTArray<RE::TESObjectREFR*> refs = dataHandler->GetFormArray<RE::TESObjectREFR>();
						////logger::debug(FMT_STRING("weapon instanceData count {}"), refs.size());
						//std::uint32_t form;
						//// get a list of all loaded TESFiles
						//RE::BSTArray<RE::TESFile*> fileList = dataHandler->compiledFileCollection.files;
						////logger::debug(FMT_STRING("files count {} "), fileList.size());
						//// iterate through each TESFile
						//for (size_t i = 0; i < fileList.size(); i++) {
						//	//logger::debug(FMT_STRING("file count {} "), i);
						//	RE::TESFile* file = fileList[i];
						//	if (!file->OpenTES(RE::NiFile::OpenMode::kReadOnly, false)) {
						//		continue;
						//	}
						//	do {
						//		if (file->currentform.formID && file->currentform.form) {
						//			form = file->currentform.form;
						//			std::string form_str(reinterpret_cast<char*>(&form), 4);
						//			if (form_str == "REFR") {
						//				auto form = RE::TESForm::GetFormByID(file->currentform.formID);
						//				if (form) {
						//					RE::TESObjectREFR* refr = static_cast<RE::TESObjectREFR*>(form);
						//					if (refr) {
						//						RE::TESBoundObject* ref = refr->GetObjectReference();
						//						if (GetPrivateProfileInt(settingsSectionFeatures, "iEnableREFRCleanupWeapons", 0, configFile) && ref && ref->formType == RE::ENUM_FORM_ID::kWEAP) {
						//							if (refr->extraList) {
						//								refr->extraList->RemoveExtra(RE::EXTRA_DATA_TYPE::kInstanceData);
						//								logger::debug(FMT_STRING("removed old start up data from refr weapon form {:08X} {} "), file->currentform.formID, form_str);
						//							}
						//						}
						//						if (GetPrivateProfileInt(settingsSectionFeatures, "iEnableREFRCleanupArmors", 0, configFile) && ref && ref->formType == RE::ENUM_FORM_ID::kARMO) {
						//							if (refr->extraList) {
						//								refr->extraList->RemoveExtra(RE::EXTRA_DATA_TYPE::kInstanceData);
						//								logger::debug(FMT_STRING("removed old start up data from refr armor form {:08X} {} "), file->currentform.formID, form_str);
						//							}
						//						}
						//					}
						//				}
						//			}
						//		}
						//	} while (file->NextForm(true));
						//	file->CloseTES(false);
						//}

						//// Create a vector of pairs
						//std::vector<std::pair<uint32_t, RE::TESForm*>> sortedForms;
						//// Populate the vector with the elements from the hash map
						//for (auto& [key, form] : *allForms.first) {
						//	sortedForms.emplace_back(key, form);
						//}

						// Sort the vector by key
						//std::sort(sortedForms.begin(), sortedForms.end());

						// Iterate over the sorted vector
						//for (auto& [key, form] : sortedForms) {
						//	// Your existing code here
						//	if (form && form->formType == RE::ENUM_FORM_ID::kREFR) {
						//		RE::TESObjectREFR* refr = static_cast<RE::TESObjectREFR*>(form);
						//		if (refr && refr->data.objectReference) {
						//			RE::TESBoundObject* ref = refr->data.objectReference;
						//			if (ref) {
						//				if (enableWeaponsCleanup && ref->formType == RE::ENUM_FORM_ID::kWEAP) {
						//					if (refr->extraList && refr->extraList->HasType(RE::EXTRA_DATA_TYPE::kInstanceData)) {
						//						refr->extraList->RemoveExtra(RE::EXTRA_DATA_TYPE::kInstanceData);
						//						logger::debug(FMT_STRING("removed old start up data from refr weapon form {:08X} "), form->formID);
						//					}
						//				}
						//				if (enableArmorsCleanup && ref->formType == RE::ENUM_FORM_ID::kARMO) {
						//					if (refr->extraList && refr->extraList->HasType(RE::EXTRA_DATA_TYPE::kInstanceData)) {
						//						refr->extraList->RemoveExtra(RE::EXTRA_DATA_TYPE::kInstanceData);
						//						logger::debug(FMT_STRING("removed old start up data from refr armor form {:08X} "), form->formID);
						//					}
						//				}
						//			}
						//		}
						//	}
						//}

						/*std::pair<RE::BSTHashMap<uint32_t, RE::TESForm*>*, std::reference_wrapper<RE::BSReadWriteLock>> allForms = RE::TESForm::GetAllForms();
						bool enableWeaponsCleanup = GetPrivateProfileInt(settingsSectionFeatures, "iEnableREFRCleanupWeapons", 0, configFile);
						bool enableArmorsCleanup = GetPrivateProfileInt(settingsSectionFeatures, "iEnableREFRCleanupArmors", 0, configFile);
						
						
						allForms.second.get().lock_write();
						for (auto& [key, form] : *allForms.first) {
							if (form && form->formType == RE::ENUM_FORM_ID::kREFR) {
								RE::TESObjectREFR* refr = static_cast<RE::TESObjectREFR*>(form);
								if (refr && refr->data.objectReference) {
									RE::TESBoundObject* ref = refr->data.objectReference;
									if (ref) {
										if (enableWeaponsCleanup && ref->formType == RE::ENUM_FORM_ID::kWEAP) {
											if (refr->extraList && refr->extraList->HasType(RE::EXTRA_DATA_TYPE::kInstanceData)) {
												refr->extraList->RemoveExtra(RE::EXTRA_DATA_TYPE::kInstanceData);
												logger::debug(FMT_STRING("removed old start up data from refr weapon form {:08X} "), form->formID);
											}
										}
										if (enableArmorsCleanup && ref->formType == RE::ENUM_FORM_ID::kARMO) {
											if (refr->extraList && refr->extraList->HasType(RE::EXTRA_DATA_TYPE::kInstanceData)) {
												refr->extraList->RemoveExtra(RE::EXTRA_DATA_TYPE::kInstanceData);
												logger::debug(FMT_STRING("removed old start up data from refr armor form {:08X} "), form->formID);
											}
										}
									}
								}
							}
						}
						allForms.second.get().unlock_write();*/

						std::pair<RE::BSTHashMap<uint32_t, RE::TESForm*>*, std::reference_wrapper<RE::BSReadWriteLock>> allForms = RE::TESForm::GetAllForms();
						//bool enableWeaponsCleanup = GetPrivateProfileInt(settingsSectionFeatures, "iEnableREFRCleanupWeapons", 0, configFile);
						//bool enableArmorsCleanup = GetPrivateProfileInt(settingsSectionFeatures, "iEnableREFRCleanupArmors", 0, configFile);

						//allForms.second.get().lock_write();
						for (auto [key, form] : *allForms.first) {
							if (form && form->formType == RE::ENUM_FORM_ID::kREFR) {
								RE::TESObjectREFR* refr = static_cast<RE::TESObjectREFR*>(form);

								if (refr && refr->data.objectReference) {
									RE::TESBoundObject* ref = refr->data.objectReference;
									if (ref) {
										if ( ref->formType == RE::ENUM_FORM_ID::kWEAP) {
											if (refr->extraList && refr->extraList->HasType(RE::EXTRA_DATA_TYPE::kInstanceData)) {
												refr->extraList->RemoveExtra(RE::EXTRA_DATA_TYPE::kInstanceData);
												
												//auto test = refr->extraList->GetByType(RE::EXTRA_DATA_TYPE::kInstanceData);
												// Assuming you have defined 'refr' and it is a valid pointer to ExtraDataList
												//int64_t instanceDataAddress = refr->extraList->GetInstanceData();
												//RE::TBO_InstanceData* InstanceData = (RE::TBO_InstanceData*)instanceDataAddress;


												
												//RE::TESObjectWEAP::InstanceData* instance = (RE::TESObjectWEAP::InstanceData*)InstanceData;
												//const RE::TBO_InstanceData* InstanceData = RE::fallout_cast<const RE::TBO_InstanceData*>(refr->extraList->GetInstanceData());

												RE::TBO_InstanceData* newRef = refr->extraList->CreateInstanceData(refr->data.objectReference, false);
												refr->extraList->SetInstanceData(newRef, refr->data.objectReference);
												logger::debug(FMT_STRING("weapon formID {:08X} created new InstanceData"), refr->formID);
												//RE::TESObjectWEAP::InstanceData* instance = (RE::TESObjectWEAP::InstanceData*)newRef;
												//auto* wrefr = (RE::TESObjectWEAP*)ref;
												//if (instance) {
												//	logger::debug(FMT_STRING("weapon formID {:08X} damage {} -> {}"), ref->formID, wrefr->weaponData.attackDamage, instance->attackDamage);
												//}
												//if (refr->extraList->HasType(RE::EXTRA_DATA_TYPE::kInstanceData)) {
												//	logger::debug(FMT_STRING("Removed - Has Instance Data"));
												//} else {
												//	logger::debug(FMT_STRING("Removed - No Instance Data"));
												//}
												//refr->extraList->CreateInstanceData(ref, false);
												//if (refr->extraList->HasType(RE::EXTRA_DATA_TYPE::kInstanceData)) {
												//	logger::debug(FMT_STRING("Added - Has Instance Data"));
												//} else {
												//	logger::debug(FMT_STRING("Added - No Instance Data"));
												//}
												//logger::debug(FMT_STRING("weapon formID {:08X}"), ref->formID);
												// Access the Data member using the arrow operator
												//RE::TESBoundObject* ref = refr->data.objectReference;
												//auto* wrefr = (RE::TESObjectWEAP*)ref;
												//RE::TESObjectWEAP::Data* data = reinterpret_cast<RE::TESObjectWEAP::Data*>(ref);
												//RE::TESObjectWEAP::InstanceData* instanceData = reinterpret_cast<RE::TESObjectWEAP::InstanceData*>(data);
												
												//logger::debug(FMT_STRING("weapon formID {:08X} damage {} ->  {}"), ref->formID, wrefr->weaponData.attackDamage, instanceData->attackDamage);
											}
										}

										//if (refr->formType == RE::ENUM_FORM_ID::kACHR) {
										//	RE::Actor* tActor = refr->As<RE::Actor>();
										//	tActor->ApplyPerksFromBase();

										//}

										//if (ref->formType == RE::ENUM_FORM_ID::kARMO) {
										//	if (refr->extraList && refr->extraList->HasType(RE::EXTRA_DATA_TYPE::kInstanceData)) {
										//		refr->extraList->RemoveExtra(RE::EXTRA_DATA_TYPE::kInstanceData);
										//		RE::TBO_InstanceData* newRef = refr->extraList->CreateInstanceData(refr->data.objectReference, false);
										//		refr->extraList->SetInstanceData(newRef, refr->data.objectReference);
										//		logger::debug(FMT_STRING("armor formID {:08X} created new InstanceData"), refr->formID);
										//		//RE::TESObjectARMO::InstanceData* instance = (RE::TESObjectARMO::InstanceData*)newRef;
										//	}
										//	//RE::TESForm* currentform = nullptr;
										//	//currentform = GetFormFromIdentifier("Fallout4.esm|4822");
										//	//logger::debug(FMT_STRING("exchanged armor {:08X} with weapon {:08X} "), form->formID, currentform->formID);
										//	//refr->data.objectReference = currentform->As<RE::TESBoundObject>();
										//}
									}
								}
							}
						}
						//allForms.second.get().unlock_write();




					}
				}

				//auto omod = (RE::BGSMod::Attachment::Mod*)GetFormFromIdentifier("Fallout4.esm|000D2A94");
				//auto data = omod->As<RE::BGSMod::Attachment::Mod::Data>();
				//logger::debug(FMT_STRING("OMOD {:08X} Fullname {}"), omod->formID, omod->fullName);
				//RE::BGSMod::Attachment::Mod::Data datatest;
				//omod->GetData(datatest);
				//for (uint32_t i = 0; i < datatest.propertyModCount; i++) {
				//	auto& mod = datatest.propertyMods[i];
				//	auto type = mod.type;
				//	std::string type_name;
				//	switch (type) {
				//	case RE::BGSMod::Property::TYPE::kInt:
				//		type_name = "kInt";
				//		logger::debug(FMT_STRING("OMOD Data Type {} kInt {} {} | {} {}"), std::to_string(mod.target), mod.data.mm.min.i, mod.data.mm.max.i, mod.data.mm.min.f, mod.data.mm.max.f);
				//		break;
				//	case RE::BGSMod::Property::TYPE::kFloat:
				//		type_name = "kFloat";
				//		logger::debug(FMT_STRING("OMOD Data Type {} kFloat {} {} | {} {}"), std::to_string(mod.target), mod.data.mm.min.f, mod.data.mm.max.f, mod.data.mm.min.i, mod.data.mm.max.i);
				//		break;
				//	case RE::BGSMod::Property::TYPE::kBool:
				//		logger::debug(FMT_STRING("OMOD Data Editor ID {:08X}"), mod.data.fv.formID);
				//		type_name = "kBool";
				//		break;
				//	case RE::BGSMod::Property::TYPE::kString:
				//		type_name = "kString";
				//		break;
				//	case RE::BGSMod::Property::TYPE::kForm:
				//		type_name = "kForm";
				//		if (mod.data.mm.min.i != 0)
				//			logger::debug(FMT_STRING("OMOD Data Type {} kForm Editor ID {:08X}"), std::to_string(mod.target), mod.data.form->formID);
				//		break;
				//	case RE::BGSMod::Property::TYPE::kEnum:
				//		type_name = "kEnum";
				//		break;
				//	case RE::BGSMod::Property::TYPE::kPair:
				//		type_name = "kPair";
				//		logger::debug(FMT_STRING("OMOD Data Type {} kPair {:08X} value {} || fmin {} fmax {} imin {} imax {} "), std::to_string(mod.target), mod.data.fv.formID, mod.data.fv.value, mod.data.mm.min.f, mod.data.mm.max.f, mod.data.mm.min.i, mod.data.mm.max.i);
				//		//mod.data.fv.value = 20.0;
				//		//logger::debug(FMT_STRING("OMOD Data Type {} kPair {:08X} value {} fmin {} fmax {} imin {} imax {} "), std::to_string(mod.target), mod.data.fv.formID, mod.data.fv.value, mod.data.mm.min.f, mod.data.mm.max.f, mod.data.mm.min.i, mod.data.mm.max.i);
				//		break;
				//	}
				//	logger::debug(FMT_STRING("OMOD Data type {}"), type_name);
				////}
				//	auto op = mod.op;
				//	std::string op_name;
				//	switch (op) {
				//	case RE::BGSMod::Property::OP::kSet:
				//		op_name = "kSet";
				//		break;
				//	case RE::BGSMod::Property::OP::kMul:
				//		op_name = "kMul/And/Rem";
				//		break;
				//	case RE::BGSMod::Property::OP::kAdd:
				//		op_name = "kAdd/Or";
				//		break;
				//	default:
				//		op_name = "Unknown";
				//	}
				//	logger::debug(FMT_STRING("OMOD Data OP {}"), op_name);
				//}

				//if (datatest) {
				//	logger::debug(FMT_STRING("OMOD Data Count {}"), datatest->propertyModCount);
				//	auto property = datatest->propertyMods;
				//} else {
				//	logger::debug(FMT_STRING("cast failed"));
				//}

				//const auto dataHandler = RE::TESDataHandler::GetSingleton();
				//RE::BSTArray<RE::TESLevItem*> objectarray = dataHandler->GetFormArray<RE::TESLevItem>();
				//for (const auto& curobj : objectarray) {
				//	if (curobj->baseListCount && curobj->leveledLists) {
				//		logger::debug(FMT_STRING("TESLEVI {:08X} Leveled List Form {:08X}"), curobj->formID, curobj->leveledLists[0].form->formID);
				//	} else {
				//		logger::debug(FMT_STRING("TESLEVI {:08X} "), curobj->formID );
				//	}
				//}

				/*					const auto dataHandler = RE::TESDataHandler::GetSingleton();
									RE::BSTArray<RE::TESNPC*> NPCArray = dataHandler->GetFormArray<RE::TESNPC>();

									for (const auto& curobj : NPCArray) {

					logge*/
				//r::debug(FMT_STRING("FormID {:08X} Class {:08X} ClassName {} {} "), curobj->formID, curobj->cl->formID, static_cast<std::string>(curobj->cl->GetFormEditorID()), curobj->cl->fullName);
				//if (curobj->formRace && curobj->originalRace) {
				//	logger::debug(FMT_STRING("FormID {:08X} Race {:08X}  original Race {:08X}"), curobj->formID, curobj->formRace->formID, curobj->originalRace->formID);
				//} else if (curobj->formRace) {
				//	logger::debug(FMT_STRING("FormID {:08X} Race {:08X} "), curobj->formID, curobj->formRace->formID);
				//} else {
				//	logger::debug(FMT_STRING("FormID {:08X} Race {:08X} "), curobj->formID, curobj->formRace->formID);
				//}
				//}

				//createForms::patchNPC();
				//}

				break;
			}
		case F4SE::MessagingInterface::kPostLoadGame:
			{

				//auto settingCol = RE::INIPrefSettingCollection::GetSingleton();
				//if (settingCol) {
				//	RE::Setting* difficulty_setting = settingCol->GetSetting("iDifficulty:GamePlay");
				//	if (difficulty_setting) {
				//		auto diff = difficulty_setting->GetInt();
				//		logger::debug(FMT_STRING("Difficulty {} "), diff);
				//	} else {
				//		logger::debug("Difficulty setting is null.");
				//	}
				//} else {
				//	logger::debug("INISettingCollection is null.");
				//}
				

				
				for (auto it = RE::GameSettingCollection::GetSingleton()->settings.begin(); it != RE::GameSettingCollection::GetSingleton()->settings.end(); ++it) {
					if (strcmp((it)->first.c_str(), "fDiffMultHPToPCTSV") == 0) {
						logger::debug(FMT_STRING("fDiffMultHPToPCTSV {} "), it->second->GetFloat());
						//logger::debug(" found");
					}
				}

				if (GetPrivateProfileInt(settingsSectionFeatures, "iEnableReCalculateStatsWithSaveLoad", 0, configFile)) {
					auto endurance = (RE::ActorValueInfo*)GetFormFromIdentifier("Fallout4.esm|000002c4");

					auto player = (RE::Actor*)GetFormFromIdentifier("Fallout4.esm|14");
					if (player) {
						player->SetBaseActorValue(*endurance, player->GetBaseActorValue(*endurance));
						logger::debug("Recalculating Player stats...");
					}
					logger::debug("Recalculating NPC stats...");
					const auto processList = RE::ProcessLists::GetSingleton();
					for (const auto& handle : processList->highActorHandles) {
						RE::Actor* actor = handle.get().get();
						if (!actor)
							continue;
						if (actor->race) {
							actor->SetBaseActorValue(*endurance, actor->GetBaseActorValue(*endurance));
						}
					}
					logger::debug(FMT_STRING("Updated {} active NPCs"), processList->highActorHandles.size());
					//for (const auto& handle : processList->middleHighActorHandles) {
					//	RE::Actor* actor = handle.get().get();
					//	if (!actor)
					//		continue;
					//	if (actor->race) {
					//		actor->SetBaseActorValue(*endurance, actor->GetBaseActorValue(*endurance));
					//	}
					//}
					//logger::debug(FMT_STRING("Updated {} inactive NPCs"), processList->middleHighActorHandles.size());
				}

				//const auto dataHandler = RE::TESDataHandler::GetSingleton();
				//RE::BSTArray<RE::NEW_REFR_DATA*> refs = dataHandler->GetFormArray<RE::NEW_REFR_DATA>();

				//auto tesfile = dataHandler->compiledFileCollection.files.at(0);
				//dataHandler
				//dataHandler->count;
				//auto objectL = dataHandler->objectList;
				//auto farrays = dataHandler->formArrays;
				////logger::debug(FMT_STRING("ref count {} formarrays size {}"), refs.size(), formarrays->size());
				//for (size_t i = 0; i < farrays->size(); i++)
				//{
				//	logger::debug(FMT_STRING("array {}"), i);
				//	if (!farrays[i].empty()) {
				//		auto &narray = farrays[i];
				//
				//	for (size_t j = 0; j < narray.size(); j++) {
				//			logger::debug(FMT_STRING("formarrays {:08X} {}"), narray[j]->formID, j);
				//		}
				//	}
				//}

				//for (const auto& ref : refs) {
				//	logger::debug(FMT_STRING("weapon instanceData curobj {:08X} ref {:08X} base formID {:08X}"), curobj->formID, ref->formID, ref->GetObjectReference()->formID);
				//	if (ref->GetObjectReference()->formID == curobj->formID) {
				//		ref->extraList->RemoveExtra(RE::EXTRA_DATA_TYPE::kInstanceData);
				//		logger::debug(FMT_STRING("weapon instanceData ref {:08X} base formID {:08X}"), ref->formID, ref->GetObjectReference()->formID);
				//	}
				//}
			}
		}
	}
}

void Init()
{
	F4SE::GetMessagingInterface()->RegisterListener(MessageHandler);
}

extern "C" DLLEXPORT bool F4SEAPI F4SEPlugin_Query(const F4SE::QueryInterface* a_f4se, F4SE::PluginInfo* a_info)
{
#ifndef NDEBUG
	auto sink = std::make_shared<spdlog::sinks::msvc_sink_mt>();
#else
	auto path = logger::log_directory();
	if (!path) {
		return false;
	}

	*path /= fmt::format(FMT_STRING("{}.log"), Version::PROJECT);
	auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true);
#endif

	auto log = std::make_shared<spdlog::logger>("global log"s, std::move(sink));

#ifndef NDEBUG
	log->set_level(spdlog::level::info);
#else

	if (GetPrivateProfileInt(settingsSectionLog, "iEnablelog", 0, configFile)) {
		log->set_level(spdlog::level::debug);
		log->flush_on(spdlog::level::debug);
	} else {
		log->set_level(spdlog::level::info);
		log->flush_on(spdlog::level::info);
	}
#endif

	spdlog::set_default_logger(std::move(log));

	spdlog::set_pattern("(%#)[%^%l%$] %v"s);
	//spdlog::set_pattern("%g(%#): [%^%l%$] %v"s);
	logger::info(FMT_STRING("{} v{}"), Version::PROJECT, Version::NAME);

	a_info->infoVersion = F4SE::PluginInfo::kVersion;
	a_info->name = Version::PROJECT.data();
	a_info->version = Version::MAJOR;

	if (a_f4se->IsEditor()) {
		logger::critical("loaded in editor"sv);
		return false;
	}

	const auto ver = a_f4se->RuntimeVersion();
	if (ver < F4SE::RUNTIME_1_10_162) {
		logger::critical(FMT_STRING("unsupported runtime v{}"), ver.string());
		return false;
	}

	return true;
}

extern "C" DLLEXPORT bool F4SEAPI F4SEPlugin_Load(const F4SE::LoadInterface* a_f4se)
{
	F4SE::Init(a_f4se);
	Init();

	return true;
}

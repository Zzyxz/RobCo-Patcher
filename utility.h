#ifndef UTILITY
#define UTILITY

using namespace std;


#include <string>
#include "PCH.h"
#include "RE/Bethesda/TESForms.h"



bool IsPluginInstalled(const char* name);

std::string to_string(RE::BIPED_MODEL::BipedObjectSlot slot);

//template <typename T>
//T* getForm(std::string form);
void RemoveOModEntry(RE::BGSMod::Attachment::Mod::Data* a_modData, uint32_t property);
uint32_t getPropertyFromString(std::string text);
int findPositionInArray(RE::BSTArray<RE::TESForm*> pArray, RE::TESForm* form);
bool changeAVIF_NPC(RE::TESNPC* pNPC, RE::ActorValueInfo* pActorValueInfo, float pfValue);
bool changeAVIF_Race(RE::TESRace* pNPC, RE::ActorValueInfo* pActorValueInfo, float pfValue);
bool changeDamageType_Weapon(RE::TESObjectWEAP* object, RE::BGSDamageType* type, float pfValue);
bool changeDamageType_Armor(RE::TESObjectARMO* object, RE::BGSDamageType* type, float pfValue);
bool changeKeyword_TESLevItem(RE::TESLevItem* pNPC, RE::BGSKeyword* pActorValueInfo, float pfValue);
bool eraseDamageType_Weapon(RE::TESObjectWEAP* object, RE::BGSDamageType* type);
	RE::EffectItem* createNewEffectItem(RE::EffectItem* item, RE::EffectSetting* setting, float magni, int dur, int area);
std::vector<std::string> splitRelationNumber(const std::string& input);
std::string trim(const std::string& str);
RE::BIPED_MODEL::BipedObjectSlot getBipedObjectSlot(int slot);

template <typename T>
T GetOffset(const void* baseObject, int offset);

RE::TESForm* GetFormFromIdentifier(const std::string& identifier);
std::string toLowerCase(std::string pString);
#endif

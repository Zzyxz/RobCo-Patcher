#ifndef GAMEFORMS_H
#define GAMEFORMS_H

using namespace std;

#include <regex>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "PCH.h"
#include "utility.h"
#include "dirent.h"

extern RE::BGSKeyword* WeaponTypeBallistic;
extern RE::BGSKeyword* WeaponTypePistol;
extern RE::BGSKeyword* WeaponTypeRifle;
extern RE::BGSKeyword* WeaponTypeShotgun;
extern RE::BGSKeyword* WeaponTypeLaser;
extern RE::BGSKeyword* WeaponTypeAlienBlaster;
extern RE::BGSKeyword* PlayerKeyword;
extern RE::BSTArray<RE::TESForm*> listPistol;
extern RE::BSTArray<RE::TESForm*> listRifle;

extern RE::TESNPC* Player;

extern RE::TESForm* Health;

extern RE::BGSListForm* BLD_F4SE_Ammo_Pistol;
extern RE::BGSListForm* BLD_F4SE_Ammo_Rifle;

namespace GAMEFORMS
{
	void DefineGameForms();
}

#endif

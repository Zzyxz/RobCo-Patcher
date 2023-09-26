#include "gameforms.h"

RE::BGSKeyword* WeaponTypeBallistic;
RE::BGSKeyword* WeaponTypePistol;
RE::BGSKeyword* WeaponTypeRifle;
RE::BGSKeyword* WeaponTypeShotgun;
RE::BGSKeyword* WeaponTypeLaser;
RE::BGSKeyword* WeaponTypeAlienBlaster;
RE::BGSKeyword* PlayerKeyword;
RE::BSTArray<RE::TESForm*> listPistol;
RE::BSTArray<RE::TESForm*> listRifle;

RE::TESNPC* Player;

RE::TESForm* Health;

RE::BGSListForm* BLD_F4SE_Ammo_Pistol;
RE::BGSListForm* BLD_F4SE_Ammo_Rifle;

namespace GAMEFORMS
{

void DefineGameForms()
{

	std::string string_form = "";
	RE::TESForm* form = nullptr;
	logger::debug("Loading Forms...");

	//Keywords
	string_form = "Fallout4.esm|00099306";
	if (string_form.length() > 0) {
		form = GetFormFromIdentifier(string_form);
		if (form && form->formType == RE::ENUM_FORM_ID::kKYWD)
			PlayerKeyword = (RE::BGSKeyword*)form;
	}
	if (!PlayerKeyword)
		logger::error(FMT_STRING("The 'PlayerKeyword' ({}) Keyword could not be found"), string_form.c_str());

	string_form = "Fallout4.esm|00092A86";
	if (string_form.length() > 0) {
		form = GetFormFromIdentifier(string_form);
		if (form && form->formType == RE::ENUM_FORM_ID::kKYWD)
			WeaponTypeBallistic = (RE::BGSKeyword*)form;
	}
	if (!WeaponTypeBallistic)
		logger::error(FMT_STRING("The 'WeaponTypeBallistic' ({}) Keyword could not be found"), string_form.c_str());

	string_form = "Fallout4.esm|0004A0A0";
	if (string_form.length() > 0) {
		form = GetFormFromIdentifier(string_form);
		if (form && form->formType == RE::ENUM_FORM_ID::kKYWD)
			WeaponTypePistol = (RE::BGSKeyword*)form;
	}
	if (!WeaponTypePistol)
		logger::error(FMT_STRING("The 'WeaponTypePistol' ({}) Keyword could not be found"), string_form.c_str());

	string_form = "Fallout4.esm|0004A0A1";
	if (string_form.length() > 0) {
		form = GetFormFromIdentifier(string_form);
		if (form && form->formType == RE::ENUM_FORM_ID::kKYWD)
			WeaponTypeRifle = (RE::BGSKeyword*)form;
	}
	if (!WeaponTypeRifle)
		logger::error(FMT_STRING("The 'WeaponTypeRifle' ({}) Keyword could not be found"), string_form.c_str());

	string_form = "Fallout4.esm|00226454";
	if (string_form.length() > 0) {
		form = GetFormFromIdentifier(string_form);
		if (form && form->formType == RE::ENUM_FORM_ID::kKYWD)
			WeaponTypeShotgun = (RE::BGSKeyword*)form;
	}
	if (!WeaponTypeShotgun)
		logger::error(FMT_STRING("The 'WeaponTypeShotgun' ({}) Keyword could not be found"), string_form.c_str());

	string_form = "Fallout4.esm|00092A84";
	if (string_form.length() > 0) {
		form = GetFormFromIdentifier(string_form);
		if (form && form->formType == RE::ENUM_FORM_ID::kKYWD)
			WeaponTypeLaser = (RE::BGSKeyword*)form;
	}
	if (!WeaponTypeLaser)
		logger::error(FMT_STRING("The 'WeaponTypeLaser' ({}) Keyword could not be found"), string_form.c_str());

	string_form = "Fallout4.esm|0016968B";
	if (string_form.length() > 0) {
		form = GetFormFromIdentifier(string_form);
		if (form && form->formType == RE::ENUM_FORM_ID::kKYWD)
			WeaponTypeAlienBlaster = (RE::BGSKeyword*)form;
	}
	if (!WeaponTypeAlienBlaster)
		logger::error(FMT_STRING("The 'WeaponTypeAlienBlaster' (%s) Keyword could not be found"), string_form.c_str());

	//projectiles
	//string_form = "Better Locational Damage.esp|000307DB";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == BGSProjectile::kTypeID)
	//		proj308 = (BGSProjectile*)form;
	//}
	//if (!proj308) _FATALERROR("The 'BLD .308 Projectile' (%s) could not be found", string_form.c_str());

	//string_form = "Better Locational Damage.esp|0001F61E";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == BGSProjectile::kTypeID)
	//		proj50 = (BGSProjectile*)form;
	//}
	//if (!proj50) _FATALERROR("The 'BLD .50 Projectile' (%s) List could not be found", string_form.c_str());

	//string_form = "Better Locational Damage - DLC_Far_Harbor.esp|0004C736";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == BGSProjectile::kTypeID)
	//		proj4570 = (BGSProjectile*)form;
	//}
	//if (!proj4570) _FATALERROR("The 'BLD 45-70 Projectile' (%s) List could not be found", string_form.c_str());

	//Formlists
	// BLD_F4SE_Ammo_Pistol "BLD_F4SE_Ammo_Pistol" [FLST:3802BD7B]
	// BLD_F4SE_Ammo_Rifle "BLD_F4SE_Ammo_Rifle" [FLST:3802BD7C]
	string_form = "Better Locational Damage.esp|0002BD7B";
	if (string_form.length() > 0) {
		form = GetFormFromIdentifier(string_form);
		if (form && form->formType == RE::ENUM_FORM_ID::kFLST) {
			BLD_F4SE_Ammo_Pistol = (RE::BGSListForm*)form;
			listPistol = BLD_F4SE_Ammo_Pistol->arrayOfForms;
		}
	}
	if (!BLD_F4SE_Ammo_Pistol) {
		//logger::error(FMT_STRING("The 'BLD_F4SE_Ammo_Pistol' (%s) List could not be found"), string_form.c_str());
	}

	string_form = "Better Locational Damage.esp|0002BD7C";
	if (string_form.length() > 0) {
		form = GetFormFromIdentifier(string_form);
		if (form && form->formType == RE::ENUM_FORM_ID::kFLST) {
			BLD_F4SE_Ammo_Rifle = (RE::BGSListForm*)form;
			listRifle = BLD_F4SE_Ammo_Rifle->arrayOfForms;
		}
	}
	if (!BLD_F4SE_Ammo_Rifle) {
		//logger::error(FMT_STRING("The 'BLD_F4SE_Ammo_Rifle' (%s) List could not be found"), string_form.c_str());
	}
	//NPC Player
	string_form = "Fallout4.esm|00000007";
	if (string_form.length() > 0) {
		form = GetFormFromIdentifier(string_form);
		if (form && form->formType == RE::ENUM_FORM_ID::kNPC_)
			Player = (RE::TESNPC*)form;
	}
	if (!Player)
		logger::error(FMT_STRING("The 'Player' ({}) Keyword could not be found"), string_form.c_str());

	//Player Health
	string_form = "Fallout4.esm|000002d4";
	if (string_form.length() > 0) {
		form = GetFormFromIdentifier(string_form);
		if (form && form->formType == RE::ENUM_FORM_ID::kAVIF)
			Health = form;
	}
	if (!Health)
		logger::error(FMT_STRING("The 'Health' ({}) Keyword could not be found"), string_form.c_str());

	//Ammo
	//
	//TESAmmo* Ammo10 = nullptr;		Ammo10mm "10mm Round" [AMMO:0001F276]
	//TESAmmo* Ammo10Comp = nullptr;	CompanionAmmo10mm "10mm Round" [AMMO:00245D6A]
	//TESAmmo* Ammo38 = nullptr;		Ammo38Caliber ".38 Round" [AMMO:0004CE87]
	//TESAmmo* Ammo44 = nullptr;		Ammo44 ".44 Round" [AMMO:0009221C]
	//TESAmmo* Ammo45 = nullptr;		Ammo45Caliber ".45 Round" [AMMO:0001F66A]
	//TESAmmo* Ammo45Comp = nullptr;	CompanionAmmo45Caliber ".45 Round" [AMMO:00245D6B]
	//TESAmmo* Ammo556 = nullptr;		Ammo556 "5.56 Round" [AMMO:0001F278]
	//TESAmmo* Ammo5mm = nullptr;		Ammo5mm "5mm Round" [AMMO:0001F66C]

	//string_form = "Fallout4.esm|0001F276";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo10 = (TESAmmo*)form;
	//		Ammo10->damage = 38.0;
	//	}
	//}
	//if (!Ammo10) _FATALERROR("The 'Ammo10' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "Fallout4.esm|00245D6A";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo10Comp = (TESAmmo*)form;
	//		Ammo10Comp->damage = 38.0;
	//	}
	//}
	//if (!Ammo10Comp) _FATALERROR("The 'Ammo10Comp' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "Fallout4.esm|0004CE87";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo38 = (TESAmmo*)form;
	//		Ammo38->damage = 36.0;
	//	}
	//}
	//if (!Ammo38) _FATALERROR("The 'Ammo38' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "Fallout4.esm|0009221C";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo44 = (TESAmmo*)form;
	//		Ammo44->damage = 59.0;
	//	}
	//}
	//if (!Ammo44) _FATALERROR("The 'Ammo44' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "Fallout4.esm|0001F66A";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo45 = (TESAmmo*)form;
	//		Ammo45->damage = 40.0;
	//	}
	//}
	//if (!Ammo45) _FATALERROR("The 'Ammo45' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "Fallout4.esm|00245D6B";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo45Comp = (TESAmmo*)form;
	//		Ammo45Comp->damage = 40.0;
	//	}
	//}
	//if (!Ammo45Comp) _FATALERROR("The 'Ammo45Comp' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "Fallout4.esm|0001F278";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo556 = (TESAmmo*)form;
	//		Ammo556->damage = 43.0;
	//	}
	//}
	//if (!Ammo556) _FATALERROR("The 'Ammo556' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "Fallout4.esm|0001F66C";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo5mm = (TESAmmo*)form;
	//		Ammo5mm->damage = 34.0;
	//	}
	//}
	//if (!Ammo5mm) _FATALERROR("The 'Ammo5mm' (%s) Ammo could not be found", string_form.c_str());

	////TESAmmo* Ammo5mmNonPlay = nullptr;Ammo5mm_NonPlayable "5mm Round" [AMMO:001943D0]
	////TESAmmo* Ammo308 = nullptr;		Ammo308Caliber ".308 Round" [AMMO:0001F66B]
	////TESAmmo* Ammo308Comp = nullptr;	CompanionAmmo308Caliber ".308 Round" [AMMO:00245D53]
	////TESAmmo* Ammo50 = nullptr;		Ammo50Caliber ".50 Caliber" [AMMO:0001F279]
	////TESAmmo* Ammo2mmEC = nullptr;		Ammo2mmEC "2mm Electromagnetic Cartridge" [AMMO:0018ABDF]
	////TESAmmo* Ammo4570 = nullptr;		DLC03_Ammo4570 ".45-70 Caliber" [AMMO:0302C8B1]
	////TESAmmo* Ammo4570Comp = nullptr;	DLC03_CompAmmo4570 ".45-70 Caliber" [AMMO:0304D39C]
	////TESAmmo* Ammo762 = nullptr;		DLC04_Ammo_HandmadeRound "7.62 Round" [AMMO:06037897]
	////TESAmmo* Ammo762Comp = nullptr;	DLC04_COM_Ammo_HandmadeRound "7.62 Round" [AMMO:060496EB]

	//string_form = "Fallout4.esm|001943D0";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo5mmNonPlay = (TESAmmo*)form;
	//		Ammo5mmNonPlay->damage = 34.0;
	//	}
	//}
	//if (!Ammo5mmNonPlay) _FATALERROR("The 'Ammo5mm' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "Fallout4.esm|0001F66B";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo308 = (TESAmmo*)form;
	//		Ammo308->damage = 84.0;

	//		if (proj308)
	//			Ammo308->projectile = proj308;
	//	}
	//}
	//if (!Ammo308) _FATALERROR("The 'Ammo308' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "Fallout4.esm|00245D53";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo308Comp = (TESAmmo*)form;
	//		Ammo308Comp->damage = 84.0;
	//		if (proj308)
	//			Ammo308Comp->projectile = proj308;
	//	}
	//}
	//if (!Ammo308Comp) _FATALERROR("The 'Ammo308Comp' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "Fallout4.esm|0001F279";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo50 = (TESAmmo*)form;
	//		Ammo50->damage = 120.0;
	//		if (proj50)
	//			Ammo50->projectile = proj50;
	//	}
	//}
	//if (!Ammo50) _FATALERROR("The 'Ammo308Comp' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "Fallout4.esm|0018ABDF";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo2mmEC = (TESAmmo*)form;
	//		Ammo2mmEC->damage = 142.0;
	//	}
	//}
	//if (!Ammo2mmEC) _FATALERROR("The 'Ammo2mmEC' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "DLCCoast.esm|0002C8B1";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo4570 = (TESAmmo*)form;
	//		Ammo4570->damage = 69.0;
	//		BLD_F4SE_Ammo_Rifle->forms.Push(Ammo4570);
	//		if (proj4570)
	//			Ammo4570->projectile = proj4570;
	//	}
	//}
	//if (!Ammo4570) _FATALERROR("The 'Ammo4570' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "DLCCoast.esm|0004D39C";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo4570Comp = (TESAmmo*)form;
	//		Ammo4570Comp->damage = 69.0;
	//		BLD_F4SE_Ammo_Rifle->forms.Push(Ammo4570Comp);
	//		if (proj4570)
	//			Ammo4570Comp->projectile = proj4570;
	//	}
	//}
	//if (!Ammo4570Comp) _FATALERROR("The 'Ammo4570Comp' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "DLCNukaWorld.esm|00037897";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo762 = (TESAmmo*)form;
	//		Ammo762->damage = 58.0;
	//		BLD_F4SE_Ammo_Rifle->forms.Push(Ammo762);
	//	}
	//}
	//if (!Ammo762) _FATALERROR("The 'Ammo762' (%s) Ammo could not be found", string_form.c_str());

	//string_form = "DLCNukaWorld.esm|000496EB";
	//if (string_form.length() > 0) {
	//	form = GetFormFromIdentifier(string_form);
	//	if (form && form->formType == TESAmmo::kTypeID) {
	//		Ammo762Comp = (TESAmmo*)form;
	//		Ammo762Comp->damage = 58.0;
	//		BLD_F4SE_Ammo_Rifle->forms.Push(Ammo762Comp);
	//	}
	//}
	//if (!Ammo762Comp) _FATALERROR("The 'Ammo762Comp' (%s) Ammo could not be found", string_form.c_str());
}

}

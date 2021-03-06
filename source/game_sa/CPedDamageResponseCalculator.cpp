#include "StdInc.h"

void CPedDamageResponseCalculator::InjectHooks()
{
    HookInstall(0x4AD3F0, &CPedDamageResponseCalculator::Constructor);
}

CPedDamageResponseCalculator::CPedDamageResponseCalculator(CEntity* pEntity, float fDamage, eWeaponType weaponType, ePedPieceTypes bodyPart, bool bSpeak)
{
#ifdef USE_DEFAULT_FUNCTIONS
    return plugin::CallMethodAndReturn<CPedDamageResponseCalculator*, 0x4AD3F0, CPedDamageResponseCalculator*, CEntity*, float, eWeaponType, ePedPieceTypes, bool>(this, pEntity, fDamage, weaponType, bodyPart, bSpeak);
#else
    m_pDamager = pEntity;
    m_fDamageFactor = fDamage;
    m_bodyPart = bodyPart;
    m_weaponType = weaponType;
    m_bSpeak = bSpeak;
#endif
}

CPedDamageResponseCalculator::~CPedDamageResponseCalculator()
{
    // nothing here
}

CPedDamageResponseCalculator* CPedDamageResponseCalculator::Constructor(CEntity * pEntity, float fDamage, eWeaponType weaponType, ePedPieceTypes bodyPart, bool bSpeak)
{
    this->CPedDamageResponseCalculator::CPedDamageResponseCalculator(pEntity, fDamage, weaponType, bodyPart, bSpeak);
    return this;
}

void CPedDamageResponseCalculator::ComputeDamageResponse(CPed * pPed, CPedDamageResponse * pDamageResponse, bool bSpeak)
{
    plugin::CallMethod<0x4B5AC0, CPedDamageResponseCalculator*, CPed *, CPedDamageResponse *, bool>(this, pPed, pDamageResponse, bSpeak);
}

#include "CEventEditableResponse.h"
#include "CPed.h"

class CEventGunShot : public CEventEditableResponse
{
public:
    CEntity* m_entity;
    CVector m_startPoint;
    CVector m_endPoint;
    bool m_bZeroLocalSoundLevel;

    static float& ms_fGunShotSenseRangeForRiot2;
    static void InjectHooks();

    CEventGunShot(CEntity* entity, CVector startPoint, CVector endPoint, bool bZeroLocalSoundLevel);
    ~CEventGunShot();
private:
    CEventGunShot* Constructor(CEntity* entity, CVector startPoint, CVector endPoint, bool bZeroLocalSoundLevel);
public:
    eEventType GetEventType() override { return EVENT_SHOT_FIRED; }
    int GetEventPriority() override { return 35; }
    int GetLifeTime() override { return 0; }
    bool AffectsPed(CPed* ped) override;
    bool IsCriminalEvent() override;
    void ReportCriminalEvent(CPed* ped) override { } // empty
    CEntity* GetSourceEntity() override { return m_entity; }
    bool TakesPriorityOver(CEvent* refEvent) override;
    float GetLocalSoundLevel() override { return m_bZeroLocalSoundLevel ? 0.0f : 160.0f; }
    bool CanBeInterruptedBySameEvent() override { return true; }
    CEventEditableResponse* CloneEditable() override;

    bool AffectsPed_Reversed(CPed* ped);
    bool IsCriminalEvent_Reversed();
    bool TakesPriorityOver_Reversed(CEvent* refEvent);
    CEventEditableResponse* CloneEditable_Reversed();
};

VALIDATE_SIZE(CEventGunShot, 0x34);

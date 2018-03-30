struct Vector 
{
	float x;
	float y;
	float z;
};

struct ColorRGBA
{
	float r;
	float g;
	float b;
	float a;
};

struct Color 
{
	unsigned char _color[4];
};

struct Vector2D 
{
	float x, y;
};

struct QAngle 
{
	float x;
	float y;
	float z;
};

struct Entity
{
	char __buf_0x00[0xCC]; // 0x0
	Vector m_vecAbsVelocity; // 0xCC
	Vector m_vecAbsOrigin; // 0xD8
	Vector m_vecOrigin; // 0xE4
	Vector m_vecAngVelocity; // 0xF0
	QAngle m_angAbsRotation; // 0xFC
	QAngle m_angRotation; // 0x108
	float m_flGravity; // 0x114
	float m_flProxyRandomValue; // 0x118
	int m_iEFlags; // 0x11C
	unsigned char m_nWaterType; // 0x120
	unsigned char m_bDormant; // 0x121
	char __buf_0x122[0x2]; // 0x122
	float m_fEffects; // 0x124
	unsigned int m_iTeamNum; // 0x128
	int m_iPendingTeamNum; // 0x12C
	char __buf_0x130[0x4]; // 0x130
	int m_iHealth; // 0x134
	int m_fFlags; // 0x138
	Vector m_vecViewOffset; // 0x13C
	Vector m_vecVelocity; // 0x148
	Vector m_vecBaseVelocity; // 0x154
	QAngle m_angNetworkAngles; // 0x160
	Vector m_vecNetworkOrigin; // 0x16C
	float m_flFriction; // 0x178
	unsigned int m_hNetworkMoveParent; // 0x17C
	unsigned int m_hOwnerEntity; // 0x180
	unsigned long long m_hGroundEntity; // 0x184
	char __buf_0x18C[0x100]; // 0x18C
	unsigned char m_nModelIndex; // 0x28C
	char __buf_0x28D[0x1]; // 0x28D
	unsigned char m_nRenderFX; // 0x28E
	unsigned char m_nRenderMode; // 0x28F
	char m_MoveType; // 0x290
	char m_MoveCollide; // 0x291
	unsigned char m_nWaterLevel; // 0x292
	char __buf_0x293[0x85]; // 0x293
	float m_flUseLookAtAngle; // 0x318
	char __buf_0x31C[0x54]; // 0x31C
	char m_ModelName; // 0x370
	char __buf_0x371[0x7]; // 0x371
	unsigned long long m_Collision; // 0x378
	char __buf_0x380[0x198]; // 0x380
	char m_rgflCoordinateFrame; // 0x518
	char __buf_0x519[0x9AF]; // 0x519
	unsigned char m_bEverHadPredictionErrorsForThisCommand; // 0xEC8
};

struct CCSPlayer
{
	char __buf_0x00[0x4144]; // 0x0
	unsigned char m_bIsScoped; // 0x4144
	char __buf_0x4145[0x1]; // 0x4145
	unsigned char m_bResumeZoom; // 0x4146
	char __buf_0x4147[0x1]; // 0x4147
	int m_iPlayerState; // 0x4148
	unsigned char m_bIsDefusing; // 0x414C
	char __buf_0x414D[0x1]; // 0x414D
	unsigned char m_bIsRescuing; // 0x414E
	char __buf_0x414F[0x1]; // 0x414F
	float m_fImmuneToGunGameDamageTime; // 0x4150
	char __buf_0x4154[0x4]; // 0x4154
	unsigned char m_bGunGameImmunity; // 0x4158
	char __buf_0x4159[0x1]; // 0x4159
	unsigned char m_bMadeFinalGunGameProgressiveKill; // 0x415A
	char __buf_0x415B[0x1]; // 0x415B
	int m_iGunGameProgressiveWeaponIndex; // 0x415C
	int m_iNumGunGameTRKillPoints; // 0x4160
	int m_iNumGunGameKillsWithCurrentWeapon; // 0x4164
	int m_iNumRoundKills; // 0x4168
	int m_iNumRoundKillsHeadshots; // 0x416C
	float m_fMolotovUseTime; // 0x4170
	float m_fMolotovDamageTime; // 0x4174
	unsigned char m_bInBombZone; // 0x4178
	char __buf_0x4179[0x1]; // 0x4179
	unsigned char m_bInNoDefuseArea; // 0x417A
	char __buf_0x417B[0x1]; // 0x417B
	int m_iThrowGrenadeCounter; // 0x417C
	int m_bWaitForNoAttack; // 0x4180
	float m_flGuardianTooFarDistFrac; // 0x4184
	float m_flDetectedByEnemySensorTime; // 0x4188
	char __buf_0x418C[0x5]; // 0x418C
	unsigned char m_bKilledByTaser; // 0x4191
	char __buf_0x4192[0x2]; // 0x4192
	int m_iMoveState; // 0x4194
	unsigned char m_bCanMoveDuringFreezePeriod; // 0x4198
	char __buf_0x4199[0x1]; // 0x4199
	int m_isCurrentGunGameTeamLeader; // 0x419A
	char __buf_0x419E[0x10A]; // 0x419E
	float m_flLowerBodyYawTarget; // 0x42A8
	int m_bStrafing; // 0x42AC
	char __buf_0x42B0[0x68C4]; // 0x42B0
	int m_iAddonBits; // 0xAB74
	int m_iPrimaryAddon; // 0xAB78
	int m_iSecondaryAddon; // 0xAB7C
	int m_iProgressBarDuration; // 0xAB80
	float m_flProgressBarStartTime; // 0xAB84
	char __buf_0xAB88[0x11]; // 0xAB88
	int m_bNightVisionOn; // 0xAB99
	char __buf_0xAB9D[0x3]; // 0xAB9D
	float m_flGroundAccelLinearFracLastTime; // 0xABA0
	int m_iStartAccount; // 0xABA4
	int m_totalHitsOnServer; // 0xABA8
	char __buf_0xABAC[0x4]; // 0xABAC
	unsigned int m_hRagdoll; // 0xABB0
	unsigned int m_hCarriedHostage; // 0xABB4
	unsigned long long m_hCarriedHostageProp; // 0xABB8
	char __buf_0xABC0[0x14]; // 0xABC0
	float m_flFlashMaxAlpha; // 0xABD4
	float m_flFlashDuration; // 0xABD8
	char __buf_0xABDC[0x40]; // 0xABDC
	int m_iMatchStats_Kills; // 0xAC1C
	char __buf_0xAC20[0x74]; // 0xAC20
	int m_iMatchStats_Damage; // 0xAC94
	char __buf_0xAC98[0x74]; // 0xAC98
	int m_iMatchStats_EquipmentValue; // 0xAD0C
	char __buf_0xAD10[0x74]; // 0xAD10
	int m_iMatchStats_MoneySaved; // 0xAD84
	char __buf_0xAD88[0x74]; // 0xAD88
	int m_iMatchStats_KillReward; // 0xADFC
	char __buf_0xAE00[0x74]; // 0xAE00
	int m_iMatchStats_LiveTime; // 0xAE74
	char __buf_0xAE78[0x74]; // 0xAE78
	int m_iMatchStats_Deaths; // 0xAEEC
	char __buf_0xAEF0[0x74]; // 0xAEF0
	int m_iMatchStats_Assists; // 0xAF64
	char __buf_0xAF68[0x74]; // 0xAF68
	int m_iMatchStats_HeadShotKills; // 0xAFDC
	char __buf_0xAFE0[0x74]; // 0xAFE0
	int m_iMatchStats_Objective; // 0xB054
	char __buf_0xB058[0x74]; // 0xB058
	int m_iMatchStats_CashEarned; // 0xB0CC
	char __buf_0xB0D0[0x74]; // 0xB0D0
	int m_iMatchStats_UtilityDamage; // 0xB144
	char __buf_0xB148[0x74]; // 0xB148
	int m_iMatchStats_EnemiesFlashed; // 0xB1BC
	char __buf_0xB1C0[0x930]; // 0xB1C0
	unsigned char m_unCurrentEquipmentValue; // 0xBAF0
	char __buf_0xBAF1[0x1]; // 0xBAF1
	unsigned char m_unRoundStartEquipmentValue; // 0xBAF2
	char __buf_0xBAF3[0x1]; // 0xBAF3
	int m_unFreezetimeEndEquipmentValue; // 0xBAF4
	int m_rank; // 0xBAF8
	char __buf_0xBAFC[0x14]; // 0xBAFC
	int m_unMusicID; // 0xBB10
	char __buf_0xBB14[0xC]; // 0xBB14
	int m_iAccount; // 0xBB20
	int m_bHasHelmet; // 0xBB24
	int m_nHeavyAssaultSuitCooldownRemaining; // 0xBB28
	int m_iClass; // 0xBB2C
	int m_ArmorValue; // 0xBB30
	QAngle m_angEyeAngles; // 0xBB34
	int m_bHasDefuser; // 0xBB40
	char __buf_0xBB44[0x1E]; // 0xBB44
	unsigned char m_bHud_MiniScoreHidden; // 0xBB62
	char __buf_0xBB63[0x1]; // 0xBB63
	int m_nLastKillerIndex; // 0xBB64
	int m_nLastConcurrentKilled; // 0xBB68
	int m_nDeathCamMusic; // 0xBB6C
	char __buf_0xBB70[0x150]; // 0xBB70
	int m_cycleLatch; // 0xBCC0
	char __buf_0xBCC4[0x490]; // 0xBCC4
	int m_bIsLookingAtWeapon; // 0xC154
	char __buf_0xC158[0x48]; // 0xC158
	float m_flThirdpersonRecoil; // 0xC1A0
	char __buf_0xC1A4[0x4D]; // 0xC1A4
	unsigned char m_bIsAssassinationTarget; // 0xC1F1
	char __buf_0xC1F2[0x1]; // 0xC1F2
	int m_bCanControlObservedBot; // 0xC1F3
	char __buf_0xC1F7[0x9]; // 0xC1F7
	int m_bHasControlledBotThisRound; // 0xC200
};

/*struct Entity 
{
	char __buf_0x00[0x88]; // 0x0
	unsigned int m_bIsAutoaimTarget; // 0x88
	unsigned int m_iEntityId; // 0x8C
	char __buf_0x8C[0x10]; // 0x90
	unsigned int m_clrRender; // 0xA0
	unsigned int m_cellbits; // 0xA4
	char __buf_0xA8[0x4]; // 0xA8
	unsigned int m_cellX; // 0xAC
	unsigned int m_cellY; // 0xB0
	unsigned int m_cellZ; // 0xB4
	char __buf_0xB8[0xC]; // 0xB8
	Vector m_vecAbsVelocity; // 0xC4
	Vector m_vecAbsOrigin; // 0xD0
	Vector m_vecOrigin; // 0xDC
	Vector m_vecAngVelocity; // 0xE8
	QAngle m_angAbsRotation; // 0xF4
	QAngle m_angRotation; // 0x100
	float m_flGravity; // 0x10C
	float m_flProxyRandomValue; // 0x110
	unsigned int m_iEFlags; // 0x114
	char __buf_0x11A[0x4];
	unsigned char m_nWaterType; // 0x118
	unsigned char m_bDormant; // 0x119
	char __buf_0x11ssA[0xA]; // 0x11A
	float m_fEffects; // 0x11C
	unsigned int 	; // 0x120
	unsigned int m_iPendingTeamNum; // 0x124
	unsigned int m_iHealth; // 0x12C
	unsigned long m_fFlags; // 0x130
	//char __buf_0x130[0x8]; // 0x134
	Vector m_vecViewOffset; // 0x134
	Vector m_vecVelocity; // 0x140
	Vector m_vecBaseVelocity; // 0x14C
	QAngle m_angNetworkAngles; // 0x158
	Vector m_vecNetworkOrigin; // 0x164
};*/
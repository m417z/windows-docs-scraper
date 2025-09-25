typedef struct _SYSTEM_POWER_STATUS {
  BYTE  ACLineStatus;
  BYTE  BatteryFlag;
  BYTE  BatteryLifePercent;
  BYTE  SystemStatusFlag;
  DWORD BatteryLifeTime;
  DWORD BatteryFullLifeTime;
} SYSTEM_POWER_STATUS, *LPSYSTEM_POWER_STATUS;
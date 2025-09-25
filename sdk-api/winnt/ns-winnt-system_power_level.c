typedef struct {
  BOOLEAN             Enable;
  BYTE                Spare[3];
  DWORD               BatteryLevel;
  POWER_ACTION_POLICY PowerPolicy;
  SYSTEM_POWER_STATE  MinSystemState;
} SYSTEM_POWER_LEVEL, *PSYSTEM_POWER_LEVEL;
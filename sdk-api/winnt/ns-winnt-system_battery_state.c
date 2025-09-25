typedef struct {
  BOOLEAN AcOnLine;
  BOOLEAN BatteryPresent;
  BOOLEAN Charging;
  BOOLEAN Discharging;
  BOOLEAN Spare1[3];
  BYTE    Tag;
  DWORD   MaxCapacity;
  DWORD   RemainingCapacity;
  DWORD   Rate;
  DWORD   EstimatedTime;
  DWORD   DefaultAlert1;
  DWORD   DefaultAlert2;
} SYSTEM_BATTERY_STATE, *PSYSTEM_BATTERY_STATE;
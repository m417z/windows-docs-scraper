typedef struct _STOR_SYSTEM_POWER_HINTS {
  ULONG             Version;
  ULONG             Size;
  RAID_SYSTEM_POWER SystemPower;
  ULONG             ResumeLatencyMSec;
} STOR_SYSTEM_POWER_HINTS, *PSTOR_SYSTEM_POWER_HINTS;
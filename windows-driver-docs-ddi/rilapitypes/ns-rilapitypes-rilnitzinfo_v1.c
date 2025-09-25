typedef struct RILNITZINFO_V1 {
  DWORD         cbSize;
  DWORD         dwParams;
  DWORD         dwExecutor;
  int           TimeZoneOffsetMinutes;
  int           DaylightSavingOffsetMinutes;
  RILSYSTEMTIME SysTime;
} RILNITZINFO_V1, *LPRILNITZINFO_V1;
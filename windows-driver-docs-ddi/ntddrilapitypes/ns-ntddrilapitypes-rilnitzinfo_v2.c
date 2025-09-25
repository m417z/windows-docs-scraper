typedef struct RILNITZINFO_V2 {
  DWORD         cbSize;
  DWORD         dwParams;
  DWORD         dwExecutor;
  int           TimeZoneOffsetMinutes;
  int           DaylightSavingOffsetMinutes;
  RILSYSTEMTIME SysTime;
  DWORD         dwSystemTypes;
} RILNITZINFO_V2, *LPRILNITZINFO_V2, RILNITZINFO, *LPRILNITZINFO;
typedef struct linecallstatus_tag {
  DWORD      dwTotalSize;
  DWORD      dwNeededSize;
  DWORD      dwUsedSize;
  DWORD      dwCallState;
  DWORD      dwCallStateMode;
  DWORD      dwCallPrivilege;
  DWORD      dwCallFeatures;
  DWORD      dwDevSpecificSize;
  DWORD      dwDevSpecificOffset;
  DWORD      dwCallFeatures2;
#if ...
  SYSTEMTIME tStateEntryTime;
#else
  WORD       tStateEntryTime[8];
#endif
} LINECALLSTATUS, *LPLINECALLSTATUS;
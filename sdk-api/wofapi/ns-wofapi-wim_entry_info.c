typedef struct _WIM_ENTRY_INFO {
  DWORD         WimEntryInfoSize;
  DWORD         WimType;
  LARGE_INTEGER DataSourceId;
  GUID          WimGuid;
  PCWSTR        WimPath;
  DWORD         WimIndex;
  DWORD         Flags;
} WIM_ENTRY_INFO, *PWIM_ENTRY_INFO;
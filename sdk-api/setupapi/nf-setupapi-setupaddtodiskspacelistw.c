WINSETUPAPI BOOL SetupAddToDiskSpaceListW(
  [in] HDSKSPC  DiskSpace,
  [in] PCWSTR   TargetFilespec,
  [in] LONGLONG FileSize,
  [in] UINT     Operation,
  [in] PVOID    Reserved1,
  [in] UINT     Reserved2
);
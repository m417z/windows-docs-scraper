WINSETUPAPI BOOL SetupAddToDiskSpaceListA(
  [in] HDSKSPC  DiskSpace,
  [in] PCSTR    TargetFilespec,
  [in] LONGLONG FileSize,
  [in] UINT     Operation,
  [in] PVOID    Reserved1,
  [in] UINT     Reserved2
);
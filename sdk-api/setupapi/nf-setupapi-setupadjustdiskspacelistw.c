WINSETUPAPI BOOL SetupAdjustDiskSpaceListW(
  [in] HDSKSPC  DiskSpace,
  [in] LPCWSTR  DriveRoot,
  [in] LONGLONG Amount,
       PVOID    Reserved1,
       UINT     Reserved2
);
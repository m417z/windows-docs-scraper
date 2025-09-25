WINSETUPAPI BOOL SetupAdjustDiskSpaceListA(
  [in] HDSKSPC  DiskSpace,
  [in] LPCSTR   DriveRoot,
  [in] LONGLONG Amount,
       PVOID    Reserved1,
       UINT     Reserved2
);
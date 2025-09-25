WINSETUPAPI BOOL SetupQuerySpaceRequiredOnDriveW(
  [in]  HDSKSPC  DiskSpace,
  [in]  PCWSTR   DriveSpec,
  [out] LONGLONG *SpaceRequired,
  [in]  PVOID    Reserved1,
  [in]  UINT     Reserved2
);
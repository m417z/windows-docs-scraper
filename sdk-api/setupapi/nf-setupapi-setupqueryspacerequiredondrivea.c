WINSETUPAPI BOOL SetupQuerySpaceRequiredOnDriveA(
  [in]  HDSKSPC  DiskSpace,
  [in]  PCSTR    DriveSpec,
  [out] LONGLONG *SpaceRequired,
  [in]  PVOID    Reserved1,
  [in]  UINT     Reserved2
);
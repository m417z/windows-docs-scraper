WINSETUPAPI BOOL SetupQueryDrivesInDiskSpaceListW(
  [in]      HDSKSPC DiskSpace,
  [in, out] PWSTR   ReturnBuffer,
  [in]      DWORD   ReturnBufferSize,
  [in, out] PDWORD  RequiredSize
);
WINSETUPAPI BOOL SetupQueryDrivesInDiskSpaceListA(
  [in]      HDSKSPC DiskSpace,
  [in, out] PSTR    ReturnBuffer,
  [in]      DWORD   ReturnBufferSize,
  [in, out] PDWORD  RequiredSize
);
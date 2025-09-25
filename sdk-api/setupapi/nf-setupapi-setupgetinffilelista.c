WINSETUPAPI BOOL SetupGetInfFileListA(
  [in]      PCSTR  DirectoryPath,
  [in]      DWORD  InfStyle,
  [in, out] PSTR   ReturnBuffer,
  [in]      DWORD  ReturnBufferSize,
  [in, out] PDWORD RequiredSize
);
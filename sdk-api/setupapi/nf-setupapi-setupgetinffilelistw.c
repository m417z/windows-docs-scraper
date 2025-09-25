WINSETUPAPI BOOL SetupGetInfFileListW(
  [in]      PCWSTR DirectoryPath,
  [in]      DWORD  InfStyle,
  [in, out] PWSTR  ReturnBuffer,
  [in]      DWORD  ReturnBufferSize,
  [in, out] PDWORD RequiredSize
);
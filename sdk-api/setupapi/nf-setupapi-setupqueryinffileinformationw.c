WINSETUPAPI BOOL SetupQueryInfFileInformationW(
  [in]      PSP_INF_INFORMATION InfInformation,
  [in]      UINT                InfIndex,
  [in, out] PWSTR               ReturnBuffer,
  [in]      DWORD               ReturnBufferSize,
  [in, out] PDWORD              RequiredSize
);
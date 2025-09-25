WINSETUPAPI BOOL SetupQueryInfFileInformationA(
  [in]      PSP_INF_INFORMATION InfInformation,
  [in]      UINT                InfIndex,
  [in, out] PSTR                ReturnBuffer,
  [in]      DWORD               ReturnBufferSize,
  [in, out] PDWORD              RequiredSize
);
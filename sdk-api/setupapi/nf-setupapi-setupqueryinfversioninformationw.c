WINSETUPAPI BOOL SetupQueryInfVersionInformationW(
  [in]      PSP_INF_INFORMATION InfInformation,
  [in]      UINT                InfIndex,
  [in]      PCWSTR              Key,
  [in, out] PWSTR               ReturnBuffer,
  [in]      DWORD               ReturnBufferSize,
  [in, out] PDWORD              RequiredSize
);
WINSETUPAPI BOOL SetupQueryInfVersionInformationA(
  [in]      PSP_INF_INFORMATION InfInformation,
  [in]      UINT                InfIndex,
  [in]      PCSTR               Key,
  [in, out] PSTR                ReturnBuffer,
  [in]      DWORD               ReturnBufferSize,
  [in, out] PDWORD              RequiredSize
);
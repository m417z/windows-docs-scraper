WINSETUPAPI BOOL SetupGetInfInformationW(
  [in]      LPCVOID             InfSpec,
  [in]      DWORD               SearchControl,
  [in, out] PSP_INF_INFORMATION ReturnBuffer,
  [in]      DWORD               ReturnBufferSize,
  [in, out] PDWORD              RequiredSize
);
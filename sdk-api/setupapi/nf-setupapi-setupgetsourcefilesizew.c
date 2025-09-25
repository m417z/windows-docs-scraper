WINSETUPAPI BOOL SetupGetSourceFileSizeW(
  [in]      HINF        InfHandle,
  [in]      PINFCONTEXT InfContext,
  [in]      PCWSTR      FileName,
  [in]      PCWSTR      Section,
  [in, out] PDWORD      FileSize,
  [in]      UINT        RoundingFactor
);
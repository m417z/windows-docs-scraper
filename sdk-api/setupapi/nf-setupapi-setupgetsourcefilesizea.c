WINSETUPAPI BOOL SetupGetSourceFileSizeA(
  [in]      HINF        InfHandle,
  [in]      PINFCONTEXT InfContext,
  [in]      PCSTR       FileName,
  [in]      PCSTR       Section,
  [in, out] PDWORD      FileSize,
  [in]      UINT        RoundingFactor
);
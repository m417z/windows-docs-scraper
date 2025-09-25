WINSETUPAPI BOOL SetupGetTargetPathA(
  [in]      HINF        InfHandle,
  [in]      PINFCONTEXT InfContext,
  [in]      PCSTR       Section,
  [in, out] PSTR        ReturnBuffer,
  [in]      DWORD       ReturnBufferSize,
  [in, out] PDWORD      RequiredSize
);
WINSETUPAPI BOOL SetupGetTargetPathW(
  [in]      HINF        InfHandle,
  [in]      PINFCONTEXT InfContext,
  [in]      PCWSTR      Section,
  [in, out] PWSTR       ReturnBuffer,
  [in]      DWORD       ReturnBufferSize,
  [in, out] PDWORD      RequiredSize
);
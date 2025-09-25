WINSETUPAPI BOOL SetupGetLineTextW(
  [in]      PINFCONTEXT Context,
  [in]      HINF        InfHandle,
  [in]      PCWSTR      Section,
  [in]      PCWSTR      Key,
  [in, out] PWSTR       ReturnBuffer,
  [in]      DWORD       ReturnBufferSize,
  [in, out] PDWORD      RequiredSize
);
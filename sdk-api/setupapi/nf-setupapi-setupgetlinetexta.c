WINSETUPAPI BOOL SetupGetLineTextA(
  [in]      PINFCONTEXT Context,
  [in]      HINF        InfHandle,
  [in]      PCSTR       Section,
  [in]      PCSTR       Key,
  [in, out] PSTR        ReturnBuffer,
  [in]      DWORD       ReturnBufferSize,
  [in, out] PDWORD      RequiredSize
);
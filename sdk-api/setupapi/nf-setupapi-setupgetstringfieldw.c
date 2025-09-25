WINSETUPAPI BOOL SetupGetStringFieldW(
  [in]      PINFCONTEXT Context,
  [in]      DWORD       FieldIndex,
  [in, out] PWSTR       ReturnBuffer,
  [in]      DWORD       ReturnBufferSize,
  [out]     PDWORD      RequiredSize
);
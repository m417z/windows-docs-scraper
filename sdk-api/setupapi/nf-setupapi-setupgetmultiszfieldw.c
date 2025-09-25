WINSETUPAPI BOOL SetupGetMultiSzFieldW(
  [in]      PINFCONTEXT Context,
  [in]      DWORD       FieldIndex,
  [in, out] PWSTR       ReturnBuffer,
  [in]      DWORD       ReturnBufferSize,
  [in]      LPDWORD     RequiredSize
);
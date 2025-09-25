WINSETUPAPI BOOL SetupGetMultiSzFieldA(
  [in]      PINFCONTEXT Context,
  [in]      DWORD       FieldIndex,
  [in, out] PSTR        ReturnBuffer,
  [in]      DWORD       ReturnBufferSize,
  [in]      LPDWORD     RequiredSize
);
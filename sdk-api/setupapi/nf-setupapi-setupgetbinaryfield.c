WINSETUPAPI BOOL SetupGetBinaryField(
  [in]      PINFCONTEXT Context,
  [in]      DWORD       FieldIndex,
  [in, out] PBYTE       ReturnBuffer,
  [in]      DWORD       ReturnBufferSize,
  [in, out] LPDWORD     RequiredSize
);
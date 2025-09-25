WINSETUPAPI BOOL SetupGetStringFieldA(
  [in]      PINFCONTEXT Context,
  [in]      DWORD       FieldIndex,
  [in, out] PSTR        ReturnBuffer,
  [in]      DWORD       ReturnBufferSize,
  [out]     PDWORD      RequiredSize
);
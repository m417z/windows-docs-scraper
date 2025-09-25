WINSETUPAPI BOOL SetupGetSourceInfoW(
  [in]      HINF   InfHandle,
  [in]      UINT   SourceId,
  [in]      UINT   InfoDesired,
  [in, out] PWSTR  ReturnBuffer,
  [in]      DWORD  ReturnBufferSize,
  [in, out] PDWORD RequiredSize
);
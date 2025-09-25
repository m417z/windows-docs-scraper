WINSETUPAPI BOOL SetupGetSourceInfoA(
  [in]      HINF   InfHandle,
  [in]      UINT   SourceId,
  [in]      UINT   InfoDesired,
  [in, out] PSTR   ReturnBuffer,
  [in]      DWORD  ReturnBufferSize,
  [in, out] PDWORD RequiredSize
);
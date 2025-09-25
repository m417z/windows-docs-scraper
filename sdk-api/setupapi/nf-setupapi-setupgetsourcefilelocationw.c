WINSETUPAPI BOOL SetupGetSourceFileLocationW(
  [in]      HINF        InfHandle,
  [in]      PINFCONTEXT InfContext,
  [in]      PCWSTR      FileName,
  [in, out] PUINT       SourceId,
  [in, out] PWSTR       ReturnBuffer,
  [out]     DWORD       ReturnBufferSize,
  [in, out] PDWORD      RequiredSize
);
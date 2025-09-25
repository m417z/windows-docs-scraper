WINSETUPAPI BOOL SetupGetSourceFileLocationA(
  [in]      HINF        InfHandle,
  [in]      PINFCONTEXT InfContext,
  [in]      PCSTR       FileName,
  [in, out] PUINT       SourceId,
  [in, out] PSTR        ReturnBuffer,
  [out]     DWORD       ReturnBufferSize,
  [in, out] PDWORD      RequiredSize
);
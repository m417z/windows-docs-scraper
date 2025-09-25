WINSETUPAPI BOOL SetupQueryFileLogW(
  [in]      HSPFILELOG       FileLogHandle,
  [in]      PCWSTR           LogSectionName,
  [in]      PCWSTR           TargetFilename,
  [in]      SetupFileLogInfo DesiredInfo,
  [in, out] PWSTR            DataOut,
  [in]      DWORD            ReturnBufferSize,
  [in, out] PDWORD           RequiredSize
);
WINSETUPAPI BOOL SetupQueryFileLogA(
  [in]      HSPFILELOG       FileLogHandle,
  [in]      PCSTR            LogSectionName,
  [in]      PCSTR            TargetFilename,
  [in]      SetupFileLogInfo DesiredInfo,
  [in, out] PSTR             DataOut,
  [in]      DWORD            ReturnBufferSize,
  [in, out] PDWORD           RequiredSize
);
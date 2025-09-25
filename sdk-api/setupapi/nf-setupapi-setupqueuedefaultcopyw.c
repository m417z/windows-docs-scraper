WINSETUPAPI BOOL SetupQueueDefaultCopyW(
  [in] HSPFILEQ QueueHandle,
  [in] HINF     InfHandle,
  [in] PCWSTR   SourceRootPath,
  [in] PCWSTR   SourceFilename,
  [in] PCWSTR   TargetFilename,
  [in] DWORD    CopyStyle
);
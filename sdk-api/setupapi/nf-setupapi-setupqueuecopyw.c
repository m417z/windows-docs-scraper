WINSETUPAPI BOOL SetupQueueCopyW(
  [in] HSPFILEQ QueueHandle,
  [in] PCWSTR   SourceRootPath,
  [in] PCWSTR   SourcePath,
  [in] PCWSTR   SourceFilename,
  [in] PCWSTR   SourceDescription,
  [in] PCWSTR   SourceTagfile,
  [in] PCWSTR   TargetDirectory,
  [in] PCWSTR   TargetFilename,
  [in] DWORD    CopyStyle
);
WINSETUPAPI BOOL SetupQueueCopyA(
  [in] HSPFILEQ QueueHandle,
  [in] PCSTR    SourceRootPath,
  [in] PCSTR    SourcePath,
  [in] PCSTR    SourceFilename,
  [in] PCSTR    SourceDescription,
  [in] PCSTR    SourceTagfile,
  [in] PCSTR    TargetDirectory,
  [in] PCSTR    TargetFilename,
  [in] DWORD    CopyStyle
);
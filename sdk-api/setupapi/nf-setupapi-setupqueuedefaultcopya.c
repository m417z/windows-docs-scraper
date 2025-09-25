WINSETUPAPI BOOL SetupQueueDefaultCopyA(
  [in] HSPFILEQ QueueHandle,
  [in] HINF     InfHandle,
  [in] PCSTR    SourceRootPath,
  [in] PCSTR    SourceFilename,
  [in] PCSTR    TargetFilename,
  [in] DWORD    CopyStyle
);
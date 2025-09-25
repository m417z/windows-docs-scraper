WINSETUPAPI BOOL SetupQueueCopySectionW(
  [in] HSPFILEQ QueueHandle,
  [in] PCWSTR   SourceRootPath,
  [in] HINF     InfHandle,
  [in] HINF     ListInfHandle,
  [in] PCWSTR   Section,
  [in] DWORD    CopyStyle
);
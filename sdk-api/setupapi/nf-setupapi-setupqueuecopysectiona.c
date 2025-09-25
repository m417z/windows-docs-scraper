WINSETUPAPI BOOL SetupQueueCopySectionA(
  [in] HSPFILEQ QueueHandle,
  [in] PCSTR    SourceRootPath,
  [in] HINF     InfHandle,
  [in] HINF     ListInfHandle,
  [in] PCSTR    Section,
  [in] DWORD    CopyStyle
);
WINSETUPAPI BOOL SetupInstallFilesFromInfSectionA(
  [in] HINF     InfHandle,
  [in] HINF     LayoutInfHandle,
  [in] HSPFILEQ FileQueue,
  [in] PCSTR    SectionName,
  [in] PCSTR    SourceRootPath,
  [in] UINT     CopyFlags
);
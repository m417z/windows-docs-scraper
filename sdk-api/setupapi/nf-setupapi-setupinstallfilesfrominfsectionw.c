WINSETUPAPI BOOL SetupInstallFilesFromInfSectionW(
  [in] HINF     InfHandle,
  [in] HINF     LayoutInfHandle,
  [in] HSPFILEQ FileQueue,
  [in] PCWSTR   SectionName,
  [in] PCWSTR   SourceRootPath,
  [in] UINT     CopyFlags
);
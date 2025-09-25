WINSETUPAPI BOOL SetupRemoveInstallSectionFromDiskSpaceListW(
  [in] HDSKSPC DiskSpace,
  [in] HINF    InfHandle,
  [in] HINF    LayoutInfHandle,
  [in] PCWSTR  SectionName,
  [in] PVOID   Reserved1,
  [in] UINT    Reserved2
);
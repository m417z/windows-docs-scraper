WINSETUPAPI BOOL SetupRemoveInstallSectionFromDiskSpaceListA(
  [in] HDSKSPC DiskSpace,
  [in] HINF    InfHandle,
  [in] HINF    LayoutInfHandle,
  [in] PCSTR   SectionName,
  [in] PVOID   Reserved1,
  [in] UINT    Reserved2
);
WINSETUPAPI BOOL SetupRemoveSectionFromDiskSpaceListA(
  [in] HDSKSPC DiskSpace,
  [in] HINF    InfHandle,
  [in] HINF    ListInfHandle,
  [in] PCSTR   SectionName,
  [in] UINT    Operation,
  [in] PVOID   Reserved1,
  [in] UINT    Reserved2
);
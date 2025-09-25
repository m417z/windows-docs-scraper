WINSETUPAPI BOOL SetupAddSectionToDiskSpaceListW(
  [in] HDSKSPC DiskSpace,
  [in] HINF    InfHandle,
  [in] HINF    ListInfHandle,
  [in] PCWSTR  SectionName,
  [in] UINT    Operation,
  [in] PVOID   Reserved1,
  [in] UINT    Reserved2
);
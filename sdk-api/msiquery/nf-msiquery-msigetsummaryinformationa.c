UINT MsiGetSummaryInformationA(
  [in]  MSIHANDLE hDatabase,
  [in]  LPCSTR    szDatabasePath,
  [in]  UINT      uiUpdateCount,
  [out] MSIHANDLE *phSummaryInfo
);
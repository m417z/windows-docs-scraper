UINT MsiGetSummaryInformationW(
  [in]  MSIHANDLE hDatabase,
  [in]  LPCWSTR   szDatabasePath,
  [in]  UINT      uiUpdateCount,
  [out] MSIHANDLE *phSummaryInfo
);
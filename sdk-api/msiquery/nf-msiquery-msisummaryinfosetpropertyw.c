UINT MsiSummaryInfoSetPropertyW(
  [in] MSIHANDLE hSummaryInfo,
  [in] UINT      uiProperty,
  [in] UINT      uiDataType,
  [in] INT       iValue,
  [in] FILETIME  *pftValue,
  [in] LPCWSTR   szValue
);
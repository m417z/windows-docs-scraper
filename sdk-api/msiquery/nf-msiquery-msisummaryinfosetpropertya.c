UINT MsiSummaryInfoSetPropertyA(
  [in] MSIHANDLE hSummaryInfo,
  [in] UINT      uiProperty,
  [in] UINT      uiDataType,
  [in] INT       iValue,
  [in] FILETIME  *pftValue,
  [in] LPCSTR    szValue
);
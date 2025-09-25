UINT MsiSummaryInfoGetPropertyW(
  [in]      MSIHANDLE hSummaryInfo,
  [in]      UINT      uiProperty,
  [out]     PUINT     puiDataType,
  [out]     LPINT     piValue,
  [out]     FILETIME  *pftValue,
  [out]     LPWSTR    szValueBuf,
  [in, out] LPDWORD   pcchValueBuf
);
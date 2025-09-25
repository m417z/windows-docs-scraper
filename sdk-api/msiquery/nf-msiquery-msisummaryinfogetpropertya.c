UINT MsiSummaryInfoGetPropertyA(
  [in]      MSIHANDLE hSummaryInfo,
  [in]      UINT      uiProperty,
  [out]     PUINT     puiDataType,
  [out]     LPINT     piValue,
  [out]     FILETIME  *pftValue,
  [out]     LPSTR     szValueBuf,
  [in, out] LPDWORD   pcchValueBuf
);
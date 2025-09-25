UINT MsiRecordGetStringW(
  [in]      MSIHANDLE hRecord,
  [in]      UINT      iField,
  [out]     LPWSTR    szValueBuf,
  [in, out] LPDWORD   pcchValueBuf
);
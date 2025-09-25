UINT MsiRecordGetStringA(
  [in]      MSIHANDLE hRecord,
  [in]      UINT      iField,
  [out]     LPSTR     szValueBuf,
  [in, out] LPDWORD   pcchValueBuf
);
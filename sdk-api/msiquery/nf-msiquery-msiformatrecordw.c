UINT MsiFormatRecordW(
  [in]      MSIHANDLE hInstall,
  [in]      MSIHANDLE hRecord,
  [out]     LPWSTR    szResultBuf,
  [in, out] LPDWORD   pcchResultBuf
);
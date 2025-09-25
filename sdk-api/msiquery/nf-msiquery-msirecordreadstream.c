UINT MsiRecordReadStream(
  [in]      MSIHANDLE hRecord,
  [in]      UINT      iField,
  [out]     char      *szDataBuf,
  [in, out] LPDWORD   pcbDataBuf
);
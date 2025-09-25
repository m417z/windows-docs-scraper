HRESULT AppendRecord(
  [in]      BLOB  *rgBlob,
  [in]      ULONG cBlob,
  [in]      BOOL  fForceNow,
  [in, out] LSN   *plsn
);
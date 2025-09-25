HRESULT SendCommandNoData(
  [in]  BYTE      *Cdb,
  [in]  ULONG     CdbSize,
  [out] BYTE [18] SenseBuffer,
  [in]  ULONG     Timeout
);
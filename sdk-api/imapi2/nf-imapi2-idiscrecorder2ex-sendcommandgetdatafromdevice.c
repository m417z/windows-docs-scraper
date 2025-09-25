HRESULT SendCommandGetDataFromDevice(
  [in]  BYTE                      *Cdb,
  [in]  ULONG                     CdbSize,
  [out] BYTE [18]                 SenseBuffer,
  [in]  ULONG                     Timeout,
  [out] BYTE                      *Buffer,
  [in]  ULONG_IMAPI2_NONZERO      BufferSize,
  [out] ULONG_IMAPI2_NOT_NEGATIVE *BufferFetched
);
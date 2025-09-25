HRESULT SendCommandSendDataToDevice(
  [in]  BYTE                 *Cdb,
  [in]  ULONG                CdbSize,
  [out] BYTE [18]            SenseBuffer,
  [in]  ULONG                Timeout,
  [in]  BYTE                 *Buffer,
  [in]  ULONG_IMAPI2_NONZERO BufferSize
);
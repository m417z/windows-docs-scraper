HRESULT SendCommand(
  [in]  UCHAR Command,
  [in]  BYTE  *pbCommandBuffer,
  [in]  ULONG cbCommandBuffer,
  [out] BYTE  *pbResponseBuffer,
  [out] ULONG *pcbResponseBuffer
);
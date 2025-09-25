HRESULT Lock2DSize(
  [in]  MF2DBuffer_LockFlags lockFlags,
  [out] BYTE                 **ppbScanline0,
  [out] LONG                 *plPitch,
  [out] BYTE                 **ppbBufferStart,
  [out] DWORD                *pcbBufferLength
);
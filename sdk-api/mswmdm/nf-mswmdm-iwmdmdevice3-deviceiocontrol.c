HRESULT DeviceIoControl(
  [in]      DWORD   dwIoControlCode,
  [in]      BYTE    *lpInBuffer,
  [in]      DWORD   nInBufferSize,
  [out]     BYTE    *lpOutBuffer,
  [in, out] LPDWORD pnOutBufferSize
);
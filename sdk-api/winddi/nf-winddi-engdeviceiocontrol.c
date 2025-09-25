ENGAPI DWORD EngDeviceIoControl(
  [in]            HANDLE  hDevice,
  [in]            DWORD   dwIoControlCode,
  [in, optional]  LPVOID  lpInBuffer,
  [in]            DWORD   nInBufferSize,
  [out, optional] LPVOID  lpOutBuffer,
  [in]            DWORD   nOutBufferSize,
  [out]           LPDWORD lpBytesReturned
);
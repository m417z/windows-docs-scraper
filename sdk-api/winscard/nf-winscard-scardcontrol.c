LONG SCardControl(
  [in]  SCARDHANDLE hCard,
  [in]  DWORD       dwControlCode,
  [in]  LPCVOID     lpInBuffer,
  [in]  DWORD       cbInBufferSize,
  [out] LPVOID      lpOutBuffer,
  [in]  DWORD       cbOutBufferSize,
  [out] LPDWORD     lpBytesReturned
);
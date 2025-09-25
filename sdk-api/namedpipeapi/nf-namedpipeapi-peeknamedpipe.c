BOOL PeekNamedPipe(
  [in]            HANDLE  hNamedPipe,
  [out, optional] LPVOID  lpBuffer,
  [in]            DWORD   nBufferSize,
  [out, optional] LPDWORD lpBytesRead,
  [out, optional] LPDWORD lpTotalBytesAvail,
  [out, optional] LPDWORD lpBytesLeftThisMessage
);
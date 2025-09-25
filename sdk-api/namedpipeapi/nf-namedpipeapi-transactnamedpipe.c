BOOL TransactNamedPipe(
  [in]                HANDLE       hNamedPipe,
  [in]                LPVOID       lpInBuffer,
  [in]                DWORD        nInBufferSize,
  [out]               LPVOID       lpOutBuffer,
  [in]                DWORD        nOutBufferSize,
  [out]               LPDWORD      lpBytesRead,
  [in, out, optional] LPOVERLAPPED lpOverlapped
);
HRESULT FilterSendMessage(
  [in]           HANDLE  hPort,
  [in, optional] LPVOID  lpInBuffer,
  [in]           DWORD   dwInBufferSize,
  [out]          LPVOID  lpOutBuffer,
  [in]           DWORD   dwOutBufferSize,
  [out]          LPDWORD lpBytesReturned
);
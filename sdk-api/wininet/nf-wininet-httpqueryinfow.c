BOOL HttpQueryInfoW(
  [in]      HINTERNET hRequest,
  [in]      DWORD     dwInfoLevel,
  [in, out] LPVOID    lpBuffer,
  [in, out] LPDWORD   lpdwBufferLength,
  [in, out] LPDWORD   lpdwIndex
);
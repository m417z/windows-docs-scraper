WINHTTPAPI BOOL WinHttpQueryHeaders(
  [in]           HINTERNET hRequest,
  [in]           DWORD     dwInfoLevel,
  [in, optional] LPCWSTR   pwszName,
  [out]          LPVOID    lpBuffer,
  [in, out]      LPDWORD   lpdwBufferLength,
  [in, out]      LPDWORD   lpdwIndex
);
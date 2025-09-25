WINHTTPAPI BOOL WinHttpQueryOption(
  [in]      HINTERNET hInternet,
  [in]      DWORD     dwOption,
  [out]     LPVOID    lpBuffer,
  [in, out] LPDWORD   lpdwBufferLength
);
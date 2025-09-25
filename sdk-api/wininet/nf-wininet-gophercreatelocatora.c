BOOL GopherCreateLocatorA(
  [in]      LPCSTR        lpszHost,
  [in]      INTERNET_PORT nServerPort,
  [in]      LPCSTR        lpszDisplayString,
  [in]      LPCSTR        lpszSelectorString,
  [in]      DWORD         dwGopherType,
  [out]     LPSTR         lpszLocator,
  [in, out] LPDWORD       lpdwBufferLength
);
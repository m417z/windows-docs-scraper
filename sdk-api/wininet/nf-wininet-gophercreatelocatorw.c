BOOL GopherCreateLocatorW(
  [in]      LPCWSTR       lpszHost,
  [in]      INTERNET_PORT nServerPort,
  [in]      LPCWSTR       lpszDisplayString,
  [in]      LPCWSTR       lpszSelectorString,
  [in]      DWORD         dwGopherType,
  [out]     LPWSTR        lpszLocator,
  [in, out] LPDWORD       lpdwBufferLength
);
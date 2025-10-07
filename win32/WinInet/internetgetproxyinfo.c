BOOL InternetGetProxyInfo(
  _In_  LPCSTR  lpszUrl,
  _In_  DWORD   dwUrlLength,
  _In_  LPSTR   lpszUrlHostName,
  _In_  DWORD   dwUrlHostNameLength,
  _Out_ LPSTR   *lplpszProxyHostName,
  _Out_ LPDWORD lpdwProxyHostNameLength
);
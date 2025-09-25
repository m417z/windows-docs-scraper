BOOL InternetGetCookieExA(
  [in]                LPCSTR  lpszUrl,
  [in]                LPCSTR  lpszCookieName,
  [in, out, optional] LPSTR   lpszCookieData,
  [in, out]           LPDWORD lpdwSize,
  [in]                DWORD   dwFlags,
  [in]                LPVOID  lpReserved
);
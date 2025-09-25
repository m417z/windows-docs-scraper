BOOL InternetGetCookieExW(
  [in]                LPCWSTR lpszUrl,
  [in]                LPCWSTR lpszCookieName,
  [in, out, optional] LPWSTR  lpszCookieData,
  [in, out]           LPDWORD lpdwSize,
  [in]                DWORD   dwFlags,
  [in]                LPVOID  lpReserved
);
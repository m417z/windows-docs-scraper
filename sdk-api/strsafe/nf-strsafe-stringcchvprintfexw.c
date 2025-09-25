STRSAFEAPI StringCchVPrintfExW(
  [out]           STRSAFE_LPWSTR  pszDest,
  [in]            size_t          cchDest,
  [out, optional] STRSAFE_LPWSTR  *ppszDestEnd,
  [out, optional] size_t          *pcchRemaining,
  [in]            DWORD           dwFlags,
  [in]            STRSAFE_LPCWSTR pszFormat,
  [in]            va_list         argList
);
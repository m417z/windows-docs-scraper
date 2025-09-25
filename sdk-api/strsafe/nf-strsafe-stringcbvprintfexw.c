STRSAFEAPI StringCbVPrintfExW(
  [out]           STRSAFE_LPWSTR  pszDest,
  [in]            size_t          cbDest,
  [out, optional] STRSAFE_LPWSTR  *ppszDestEnd,
  [out, optional] size_t          *pcbRemaining,
  [in]            DWORD           dwFlags,
  [in]            STRSAFE_LPCWSTR pszFormat,
  [in]            va_list         argList
);
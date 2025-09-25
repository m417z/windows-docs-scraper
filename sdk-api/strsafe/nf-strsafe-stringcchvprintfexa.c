STRSAFEAPI StringCchVPrintfExA(
  [out]           STRSAFE_LPSTR  pszDest,
  [in]            size_t         cchDest,
  [out, optional] STRSAFE_LPSTR  *ppszDestEnd,
  [out, optional] size_t         *pcchRemaining,
  [in]            DWORD          dwFlags,
  [in]            STRSAFE_LPCSTR pszFormat,
  [in]            va_list        argList
);
STRSAFEAPI StringCchCopyExA(
  [out]           STRSAFE_LPSTR  pszDest,
  [in]            size_t         cchDest,
  [in]            STRSAFE_LPCSTR pszSrc,
  [out, optional] STRSAFE_LPSTR  *ppszDestEnd,
  [out, optional] size_t         *pcchRemaining,
  [in]            DWORD          dwFlags
);
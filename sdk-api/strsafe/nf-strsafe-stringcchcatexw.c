STRSAFEAPI StringCchCatExW(
  [in, out]       STRSAFE_LPWSTR  pszDest,
  [in]            size_t          cchDest,
  [in]            STRSAFE_LPCWSTR pszSrc,
  [out, optional] STRSAFE_LPWSTR  *ppszDestEnd,
  [out, optional] size_t          *pcchRemaining,
  [in]            DWORD           dwFlags
);
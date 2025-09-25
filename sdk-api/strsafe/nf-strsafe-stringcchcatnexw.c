STRSAFEAPI StringCchCatNExW(
  [in, out]       STRSAFE_LPWSTR  pszDest,
  [in]            size_t          cchDest,
  [in]            STRSAFE_PCNZWCH pszSrc,
  [in]            size_t          cchToAppend,
  [out, optional] STRSAFE_LPWSTR  *ppszDestEnd,
  [out, optional] size_t          *pcchRemaining,
  [in]            DWORD           dwFlags
);
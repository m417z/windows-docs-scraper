STRSAFEAPI StringCbCatNExW(
  [in, out]       STRSAFE_LPWSTR  pszDest,
  [in]            size_t          cbDest,
  [in]            STRSAFE_PCNZWCH pszSrc,
  [in]            size_t          cbToAppend,
  [out, optional] STRSAFE_LPWSTR  *ppszDestEnd,
  [out, optional] size_t          *pcbRemaining,
  [in]            DWORD           dwFlags
);
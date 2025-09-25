STRSAFEAPI StringCchCopyNExW(
  [out]           STRSAFE_LPWSTR  pszDest,
  [in]            size_t          cchDest,
  [in]            STRSAFE_PCNZWCH pszSrc,
  [in]            size_t          cchToCopy,
  [out, optional] STRSAFE_LPWSTR  *ppszDestEnd,
  [out, optional] size_t          *pcchRemaining,
  [in]            DWORD           dwFlags
);
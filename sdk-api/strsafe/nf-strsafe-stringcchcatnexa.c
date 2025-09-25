STRSAFEAPI StringCchCatNExA(
  [in, out]       STRSAFE_LPSTR  pszDest,
  [in]            size_t         cchDest,
  [in]            STRSAFE_PCNZCH pszSrc,
  [in]            size_t         cchToAppend,
  [out, optional] STRSAFE_LPSTR  *ppszDestEnd,
  [out, optional] size_t         *pcchRemaining,
  [in]            DWORD          dwFlags
);
STRSAFEAPI StringCbCatNExA(
  [in, out]       STRSAFE_LPSTR  pszDest,
  [in]            size_t         cbDest,
  [in]            STRSAFE_PCNZCH pszSrc,
  [in]            size_t         cbToAppend,
  [out, optional] STRSAFE_LPSTR  *ppszDestEnd,
  [out, optional] size_t         *pcbRemaining,
  [in]            DWORD          dwFlags
);
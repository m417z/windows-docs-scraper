STRSAFEAPI StringCbCopyExA(
  [out]           STRSAFE_LPSTR  pszDest,
  [in]            size_t         cbDest,
  [in]            STRSAFE_LPCSTR pszSrc,
  [out, optional] STRSAFE_LPSTR  *ppszDestEnd,
  [out, optional] size_t         *pcbRemaining,
  [in]            DWORD          dwFlags
);
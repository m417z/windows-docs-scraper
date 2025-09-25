STRSAFEAPI StringCbGetsExW(
  [out]           STRSAFE_LPWSTR pszDest,
  [in]            size_t         cbDest,
  [out, optional] STRSAFE_LPWSTR *ppszDestEnd,
  [out, optional] size_t         *pcbRemaining,
  [in]            DWORD          dwFlags
);
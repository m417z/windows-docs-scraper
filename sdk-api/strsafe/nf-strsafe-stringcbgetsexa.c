STRSAFEAPI StringCbGetsExA(
  [out]           STRSAFE_LPSTR pszDest,
  [in]            size_t        cbDest,
  [out, optional] STRSAFE_LPSTR *ppszDestEnd,
  [out, optional] size_t        *pcbRemaining,
  [in]            DWORD         dwFlags
);
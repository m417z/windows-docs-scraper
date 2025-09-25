STRSAFEAPI StringCchGetsExW(
  [out]           STRSAFE_LPWSTR pszDest,
  [in]            size_t         cchDest,
  [out, optional] STRSAFE_LPWSTR *ppszDestEnd,
  [out, optional] size_t         *pcchRemaining,
  [in]            DWORD          dwFlags
);
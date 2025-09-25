WINPATHCCHAPI HRESULT PathCchAddBackslashEx(
  [in, out]       PWSTR  pszPath,
  [in]            size_t cchPath,
  [out, optional] PWSTR  *ppszEnd,
  [out, optional] size_t *pcchRemaining
);
WINPATHCCHAPI HRESULT PathCchCombineEx(
  [out]          PWSTR  pszPathOut,
  [in]           size_t cchPathOut,
  [in, optional] PCWSTR pszPathIn,
  [in, optional] PCWSTR pszMore,
  [in]           ULONG  dwFlags
);
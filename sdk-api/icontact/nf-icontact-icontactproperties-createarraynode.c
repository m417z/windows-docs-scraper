HRESULT CreateArrayNode(
  [in]      LPCWSTR pszArrayName,
  [in]      DWORD   dwFlags,
  [in]      BOOL    fAppend,
  [in, out] LPWSTR  pszNewArrayElementName,
  [in]      DWORD   cchNewArrayElementName,
  [in, out] DWORD   *pdwcchNewArrayElementNameRequired
);
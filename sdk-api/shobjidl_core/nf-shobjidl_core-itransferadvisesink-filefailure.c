HRESULT FileFailure(
  [in]      IShellItem *psi,
  [in]      LPCWSTR    pszItem,
  [in]      HRESULT    hrError,
  [in, out] LPWSTR     pszRename,
  [in]      ULONG      cchRename
);
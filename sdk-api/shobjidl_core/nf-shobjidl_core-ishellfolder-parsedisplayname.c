HRESULT ParseDisplayName(
  [in]      HWND             hwnd,
  [in]      IBindCtx         *pbc,
  [in]      LPWSTR           pszDisplayName,
  [out]     ULONG            *pchEaten,
  [out]     PIDLIST_RELATIVE *ppidl,
  [in, out] ULONG            *pdwAttributes
);
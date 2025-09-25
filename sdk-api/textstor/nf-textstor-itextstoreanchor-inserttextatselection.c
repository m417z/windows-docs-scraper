HRESULT InsertTextAtSelection(
  [in]  DWORD       dwFlags,
  [in]  const WCHAR *pchText,
  [in]  ULONG       cch,
  [out] IAnchor     **ppaStart,
  [out] IAnchor     **ppaEnd
);
HRESULT InsertTextAtSelection(
  [in]  TfEditCookie ec,
  [in]  DWORD        dwFlags,
  [in]  const WCHAR  *pchText,
  [in]  LONG         cch,
  [out] ITfRange     **ppRange
);
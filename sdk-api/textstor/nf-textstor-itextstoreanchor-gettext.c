HRESULT GetText(
  [in]  DWORD   dwFlags,
  [in]  IAnchor *paStart,
  [in]  IAnchor *paEnd,
  [out] WCHAR   *pchText,
  [in]  ULONG   cchReq,
  [out] ULONG   *pcch,
  [in]  BOOL    fUpdateAnchor
);
HRESULT VarFormatFromTokens(
  [in]           LPVARIANT pvarIn,
  [in, optional] LPOLESTR  pstrFormat,
  [in]           LPBYTE    pbTokCur,
  [in]           ULONG     dwFlags,
  [out]          BSTR      *pbstrOut,
  [in]           LCID      lcid
);
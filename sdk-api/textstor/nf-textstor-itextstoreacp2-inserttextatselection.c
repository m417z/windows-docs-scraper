HRESULT InsertTextAtSelection(
  [in]  DWORD         dwFlags,
  [in]  const WCHAR   *pchText,
  [in]  ULONG         cch,
  [out] LONG          *pacpStart,
  [out] LONG          *pacpEnd,
  [out] TS_TEXTCHANGE *pChange
);
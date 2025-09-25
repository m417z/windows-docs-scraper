HRESULT SetText(
  [in]  DWORD         dwFlags,
  [in]  LONG          acpStart,
  [in]  LONG          acpEnd,
  [in]  const WCHAR   *pchText,
  [in]  ULONG         cch,
  [out] TS_TEXTCHANGE *pChange
);
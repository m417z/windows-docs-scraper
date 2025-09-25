HRESULT FormatForDisplay(
  [in]  REFFMTID                fmtid,
  [in]  PROPID                  pid,
  [in]  const PROPVARIANT       *ppropvar,
  [in]  PROPERTYUI_FORMAT_FLAGS puiff,
  [out] LPWSTR                  pwszText,
  [in]  DWORD                   cchText
);
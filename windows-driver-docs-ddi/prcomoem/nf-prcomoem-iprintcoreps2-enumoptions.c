HRESULT EnumOptions(
  [in]  PDEVOBJ pdevobj,
  [in]  DWORD   dwFlags,
  [in]  PCSTR   pszFeatureKeyword,
  [out] PSTR    pmszOptionList,
  [in]  DWORD   cbSize,
  [out] PDWORD  pcbNeeded
);
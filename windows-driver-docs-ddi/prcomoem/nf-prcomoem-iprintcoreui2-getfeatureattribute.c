HRESULT GetFeatureAttribute(
  [in]  POEMUIOBJ poemuiobj,
  [in]  DWORD     dwFlags,
  [in]  PCSTR     pszFeatureKeyword,
  [in]  PCSTR     pszAttribute,
  [out] PDWORD    pdwDataType,
  [out] PBYTE     pbData,
  [in]  DWORD     cbSize,
  [out] PDWORD    pcbNeeded
);
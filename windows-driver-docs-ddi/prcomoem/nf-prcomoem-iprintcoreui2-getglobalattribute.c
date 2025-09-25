HRESULT GetGlobalAttribute(
  [in]  POEMUIOBJ poemuiobj,
  [in]  DWORD     dwFlags,
  [in]  PCSTR     pszAttribute,
  [out] PDWORD    pdwDataType,
  [out] PBYTE     pbData,
  [in]  DWORD     cbSize,
  [out] PDWORD    pcbNeeded
);
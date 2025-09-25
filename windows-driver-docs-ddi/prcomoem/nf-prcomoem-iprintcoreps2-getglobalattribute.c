HRESULT GetGlobalAttribute(
  [in]  PDEVOBJ pdevobj,
  [in]  DWORD   dwFlags,
  [in]  PCSTR   pszAttribute,
  [out] PDWORD  pdwDataType,
  [out] PBYTE   pbData,
  [in]  DWORD   cbSize,
  [out] PDWORD  pcbNeeded
);
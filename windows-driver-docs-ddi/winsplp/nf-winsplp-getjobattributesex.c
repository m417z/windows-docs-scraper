BOOL GetJobAttributesEx(
  [in]  LPWSTR     pPrinterName,
  [in]  LPDEVMODEW pDevmode,
  [in]  DWORD      dwLevel,
  [out] LPBYTE     pAttributeInfo,
  [in]  DWORD      nSize,
  [in]  DWORD      dwFlags
);
UINT MsiGetProductPropertyW(
  [in]      MSIHANDLE hProduct,
  [in]      LPCWSTR   szProperty,
  [out]     LPWSTR    lpValueBuf,
  [in, out] LPDWORD   pcchValueBuf
);
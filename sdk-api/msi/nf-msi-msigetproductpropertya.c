UINT MsiGetProductPropertyA(
  [in]      MSIHANDLE hProduct,
  [in]      LPCSTR    szProperty,
  [out]     LPSTR     lpValueBuf,
  [in, out] LPDWORD   pcchValueBuf
);
UINT MsiProvideComponentA(
  [in]      LPCSTR  szProduct,
  [in]      LPCSTR  szFeature,
  [in]      LPCSTR  szComponent,
  [in]      DWORD   dwInstallMode,
  [out]     LPSTR   lpPathBuf,
  [in, out] LPDWORD pcchPathBuf
);
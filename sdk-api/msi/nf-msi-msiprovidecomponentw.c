UINT MsiProvideComponentW(
  [in]      LPCWSTR szProduct,
  [in]      LPCWSTR szFeature,
  [in]      LPCWSTR szComponent,
  [in]      DWORD   dwInstallMode,
  [out]     LPWSTR  lpPathBuf,
  [in, out] LPDWORD pcchPathBuf
);
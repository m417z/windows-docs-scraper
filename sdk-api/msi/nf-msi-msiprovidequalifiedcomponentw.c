UINT MsiProvideQualifiedComponentW(
  [in]      LPCWSTR szCategory,
  [in]      LPCWSTR szQualifier,
  [in]      DWORD   dwInstallMode,
  [out]     LPWSTR  lpPathBuf,
  [in, out] LPDWORD pcchPathBuf
);
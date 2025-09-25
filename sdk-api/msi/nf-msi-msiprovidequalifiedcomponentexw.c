UINT MsiProvideQualifiedComponentExW(
  [in]      LPCWSTR szCategory,
  [in]      LPCWSTR szQualifier,
  [in]      DWORD   dwInstallMode,
  [in]      LPCWSTR szProduct,
  [in]      DWORD   dwUnused1,
  [in]      DWORD   dwUnused2,
  [out]     LPWSTR  lpPathBuf,
  [in, out] LPDWORD pcchPathBuf
);
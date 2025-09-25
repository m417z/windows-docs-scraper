UINT MsiProvideAssemblyW(
  [in]      LPCWSTR szAssemblyName,
  [in]      LPCWSTR szAppContext,
  [in]      DWORD   dwInstallMode,
  [in]      DWORD   dwAssemblyInfo,
  [out]     LPWSTR  lpPathBuf,
  [in, out] LPDWORD pcchPathBuf
);
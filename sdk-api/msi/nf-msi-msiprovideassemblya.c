UINT MsiProvideAssemblyA(
  [in]      LPCSTR  szAssemblyName,
  [in]      LPCSTR  szAppContext,
  [in]      DWORD   dwInstallMode,
  [in]      DWORD   dwAssemblyInfo,
  [out]     LPSTR   lpPathBuf,
  [in, out] LPDWORD pcchPathBuf
);
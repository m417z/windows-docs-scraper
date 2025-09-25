UINT MsiProvideQualifiedComponentA(
  [in]      LPCSTR  szCategory,
  [in]      LPCSTR  szQualifier,
  [in]      DWORD   dwInstallMode,
  [out]     LPSTR   lpPathBuf,
  [in, out] LPDWORD pcchPathBuf
);
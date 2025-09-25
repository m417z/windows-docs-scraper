UINT MsiProvideQualifiedComponentExA(
  [in]      LPCSTR  szCategory,
  [in]      LPCSTR  szQualifier,
  [in]      DWORD   dwInstallMode,
  [in]      LPCSTR  szProduct,
  [in]      DWORD   dwUnused1,
  [in]      DWORD   dwUnused2,
  [out]     LPSTR   lpPathBuf,
  [in, out] LPDWORD pcchPathBuf
);
UINT MsiGetPropertyW(
  [in]      MSIHANDLE hInstall,
  [in]      LPCWSTR   szName,
  [out]     LPWSTR    szValueBuf,
  [in, out] LPDWORD   pcchValueBuf
);
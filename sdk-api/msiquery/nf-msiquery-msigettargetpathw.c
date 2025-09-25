UINT MsiGetTargetPathW(
  [in]      MSIHANDLE hInstall,
  [in]      LPCWSTR   szFolder,
  [out]     LPWSTR    szPathBuf,
  [in, out] LPDWORD   pcchPathBuf
);
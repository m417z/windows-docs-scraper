UINT MsiGetComponentStateW(
  [in]  MSIHANDLE    hInstall,
  [in]  LPCWSTR      szComponent,
  [out] INSTALLSTATE *piInstalled,
  [out] INSTALLSTATE *piAction
);
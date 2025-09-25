UINT MsiGetComponentStateA(
  [in]  MSIHANDLE    hInstall,
  [in]  LPCSTR       szComponent,
  [out] INSTALLSTATE *piInstalled,
  [out] INSTALLSTATE *piAction
);
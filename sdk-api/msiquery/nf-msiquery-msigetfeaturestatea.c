UINT MsiGetFeatureStateA(
  [in]  MSIHANDLE    hInstall,
  [in]  LPCSTR       szFeature,
  [out] INSTALLSTATE *piInstalled,
  [out] INSTALLSTATE *piAction
);
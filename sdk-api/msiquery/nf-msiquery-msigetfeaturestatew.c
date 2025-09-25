UINT MsiGetFeatureStateW(
  [in]  MSIHANDLE    hInstall,
  [in]  LPCWSTR      szFeature,
  [out] INSTALLSTATE *piInstalled,
  [out] INSTALLSTATE *piAction
);
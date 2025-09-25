UINT MsiGetFeatureCostW(
  [in]  MSIHANDLE    hInstall,
  [in]  LPCWSTR      szFeature,
  [in]  MSICOSTTREE  iCostTree,
  [in]  INSTALLSTATE iState,
  [out] LPINT        piCost
);
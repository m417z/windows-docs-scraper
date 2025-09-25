UINT MsiGetFeatureCostA(
  [in]  MSIHANDLE    hInstall,
  [in]  LPCSTR       szFeature,
  [in]  MSICOSTTREE  iCostTree,
  [in]  INSTALLSTATE iState,
  [out] LPINT        piCost
);
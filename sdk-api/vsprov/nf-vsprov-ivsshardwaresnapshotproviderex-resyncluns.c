HRESULT ResyncLuns(
  [in]  VDS_LUN_INFORMATION *pSourceLuns,
  [in]  VDS_LUN_INFORMATION *pTargetLuns,
  [in]  DWORD               dwCount,
  [out] IVssAsync           **ppAsync
);
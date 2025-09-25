HRESULT UninstallDisks(
  [in]  VDS_OBJECT_ID *pDiskIdArray,
  [in]  ULONG         ulCount,
  [in]  BOOLEAN       bForce,
  [out] BOOLEAN       *pbReboot,
  [out] HRESULT       *pResults
);
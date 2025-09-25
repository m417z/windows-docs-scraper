HRESULT CopyTo(
  [in]            long       lFlags,
  [in]            IGPMDomain *pIGPMDomain,
  [in, optional]  VARIANT    *pvarNewDisplayName,
  [in, optional]  VARIANT    *pvarMigrationTable,
  [in, optional]  VARIANT    *pvarGPMProgress,
  [out, optional] VARIANT    *pvarGPMCancel,
  [out]           IGPMResult **ppIGPMResult
);
HRESULT Import(
  [in]            long       lFlags,
  [in]            IGPMBackup *pIGPMBackup,
  [in, optional]  VARIANT    *pvarMigrationTable,
  [in, optional]  VARIANT    *pvarGPMProgress,
  [out, optional] VARIANT    *pvarGPMCancel,
  [out]           IGPMResult **ppIGPMResult
);
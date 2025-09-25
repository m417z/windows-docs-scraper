HRESULT RestoreStarterGPO(
  [in]            IGPMStarterGPOBackup *pIGPMTmplBackup,
  [in, optional]  VARIANT              *pvarGPMProgress,
  [out, optional] VARIANT              *pvarGPMCancel,
  [out]           IGPMResult           **ppIGPMResult
);
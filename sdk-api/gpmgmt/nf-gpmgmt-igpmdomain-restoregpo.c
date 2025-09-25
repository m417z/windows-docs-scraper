HRESULT RestoreGPO(
  [in]            IGPMBackup *pIGPMBackup,
  [in]            long       lDCFlags,
  [in, optional]  VARIANT    *pvarGPMProgress,
  [out, optional] VARIANT    *pvarGPMCancel,
  [out]           IGPMResult **ppIGPMResult
);
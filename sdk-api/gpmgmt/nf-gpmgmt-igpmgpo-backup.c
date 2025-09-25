HRESULT Backup(
  [in]            BSTR       bstrBackupDir,
  [in]            BSTR       bstrComment,
  [in, optional]  VARIANT    *pvarGPMProgress,
  [out, optional] VARIANT    *pvarGPMCancel,
  [out]           IGPMResult **ppIGPMResult
);
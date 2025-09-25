HRESULT CopyCaptureFile(
  [in] LPOLESTR                   lpwstrOld,
  [in] LPOLESTR                   lpwstrNew,
  [in] int                        fAllowEscAbort,
  [in] IAMCopyCaptureFileProgress *pCallback
);
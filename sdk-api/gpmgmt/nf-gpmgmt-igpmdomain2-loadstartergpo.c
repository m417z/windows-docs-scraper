HRESULT LoadStarterGPO(
  [in]            BSTR         bstrLoadFile,
  [in]            VARIANT_BOOL bOverwrite,
  [in, optional]  VARIANT      *pvarGPMProgress,
  [out, optional] VARIANT      *pvarGPMCancel,
  [out]           IGPMResult   **ppIGPMResult
);
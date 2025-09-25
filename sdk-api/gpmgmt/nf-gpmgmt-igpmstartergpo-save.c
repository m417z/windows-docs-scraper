HRESULT Save(
  [in]            BSTR         bstrSaveFile,
  [in]            VARIANT_BOOL bOverwrite,
  [in]            VARIANT_BOOL bSaveAsSystem,
  [in, optional]  VARIANT      *bstrLanguage,
  [in, optional]  VARIANT      *bstrAuthor,
  [in, optional]  VARIANT      *bstrProduct,
  [in, optional]  VARIANT      *bstrUniqueID,
  [in, optional]  VARIANT      *bstrVersion,
  [in, optional]  VARIANT      *pvarGPMProgress,
  [out, optional] VARIANT      *pvarGPMCancel,
  [out]           IGPMResult   **ppIGPMResult
);
HRESULT CAImportPFX(
  [in]  const BSTR                  bstrFileName,
  [in]  const BSTR                  bstrPasswd,
  [in]  VARIANT_BOOL                bOverwriteExistingKey,
  [out] ICertSrvSetupKeyInformation **ppVal
);
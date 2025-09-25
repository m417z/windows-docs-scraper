HRESULT CreatePKCS7RequestFromRequest(
  [in]  PCRYPT_DATA_BLOB pRequest,
  [in]  PCCERT_CONTEXT   pSigningCertContext,
  [out] PCRYPT_DATA_BLOB pPkcs7Blob
);
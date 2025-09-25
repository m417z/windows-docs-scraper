BOOL CertFindSubjectInSortedCTL(
  [in]  PCRYPT_DATA_BLOB pSubjectIdentifier,
  [in]  PCCTL_CONTEXT    pCtlContext,
  [in]  DWORD            dwFlags,
  [in]  void             *pvReserved,
  [out] PCRYPT_DER_BLOB  pEncodedAttributes
);
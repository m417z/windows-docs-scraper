BOOL CertEnumSubjectInSortedCTL(
  [in]      PCCTL_CONTEXT   pCtlContext,
  [in, out] void            **ppvNextSubject,
  [out]     PCRYPT_DER_BLOB pSubjectIdentifier,
  [out]     PCRYPT_DER_BLOB pEncodedAttributes
);
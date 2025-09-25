BOOL CertGetEnhancedKeyUsage(
  [in]      PCCERT_CONTEXT     pCertContext,
  [in]      DWORD              dwFlags,
  [out]     PCERT_ENHKEY_USAGE pUsage,
  [in, out] DWORD              *pcbUsage
);
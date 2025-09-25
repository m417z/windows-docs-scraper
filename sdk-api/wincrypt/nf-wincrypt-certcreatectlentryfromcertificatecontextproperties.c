BOOL CertCreateCTLEntryFromCertificateContextProperties(
  [in]      PCCERT_CONTEXT   pCertContext,
  [in]      DWORD            cOptAttr,
  [in]      PCRYPT_ATTRIBUTE rgOptAttr,
  [in]      DWORD            dwFlags,
  [in]      void             *pvReserved,
  [out]     PCTL_ENTRY       pCtlEntry,
  [in, out] DWORD            *pcbCtlEntry
);
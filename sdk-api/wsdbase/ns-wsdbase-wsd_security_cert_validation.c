typedef struct _WSD_SECURITY_CERT_VALIDATION {
  PCCERT_CONTEXT *certMatchArray;
  DWORD          dwCertMatchArrayCount;
  HCERTSTORE     hCertMatchStore;
  HCERTSTORE     hCertIssuerStore;
  DWORD          dwCertCheckOptions;
  LPCWSTR        pszCNGHashAlgId;
  BYTE           *pbCertHash;
  DWORD          dwCertHashSize;
} WSD_SECURITY_CERT_VALIDATION;
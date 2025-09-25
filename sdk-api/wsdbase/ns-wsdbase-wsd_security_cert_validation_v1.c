typedef struct _WSD_SECURITY_CERT_VALIDATION_V1 {
  PCCERT_CONTEXT *certMatchArray;
  DWORD          dwCertMatchArrayCount;
  HCERTSTORE     hCertMatchStore;
  HCERTSTORE     hCertIssuerStore;
  DWORD          dwCertCheckOptions;
} WSD_SECURITY_CERT_VALIDATION_V1;
typedef struct _CERT_CONTEXT {
  DWORD      dwCertEncodingType;
  BYTE       *pbCertEncoded;
  DWORD      cbCertEncoded;
  PCERT_INFO pCertInfo;
  HCERTSTORE hCertStore;
} CERT_CONTEXT, *PCERT_CONTEXT;
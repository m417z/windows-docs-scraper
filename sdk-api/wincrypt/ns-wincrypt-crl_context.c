typedef struct _CRL_CONTEXT {
  DWORD      dwCertEncodingType;
  BYTE       *pbCrlEncoded;
  DWORD      cbCrlEncoded;
  PCRL_INFO  pCrlInfo;
  HCERTSTORE hCertStore;
} CRL_CONTEXT, *PCRL_CONTEXT;
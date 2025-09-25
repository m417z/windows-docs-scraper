typedef struct _CRYPT_PROVIDER_CERT {
  DWORD               cbStruct;
  PCCERT_CONTEXT      pCert;
  BOOL                fCommercial;
  BOOL                fTrustedRoot;
  BOOL                fSelfSigned;
  BOOL                fTestCert;
  DWORD               dwRevokedReason;
  DWORD               dwConfidence;
  DWORD               dwError;
  CTL_CONTEXT         *pTrustListContext;
  BOOL                fTrustListSignerCert;
  PCCTL_CONTEXT       pCtlContext;
  DWORD               dwCtlError;
  BOOL                fIsCyclic;
  PCERT_CHAIN_ELEMENT pChainElement;
} CRYPT_PROVIDER_CERT, *PCRYPT_PROVIDER_CERT;
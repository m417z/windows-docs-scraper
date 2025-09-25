typedef struct _CERT_REVOCATION_PARA {
  DWORD                       cbSize;
  PCCERT_CONTEXT              pIssuerCert;
  DWORD                       cCertStore;
  HCERTSTORE                  *rgCertStore;
  HCERTSTORE                  hCrlStore;
  LPFILETIME                  pftTimeToUse;
  DWORD                       dwUrlRetrievalTimeout;
  BOOL                        fCheckFreshnessTime;
  DWORD                       dwFreshnessTime;
  LPFILETIME                  pftCurrentTime;
  PCERT_REVOCATION_CRL_INFO   pCrlInfo;
  LPFILETIME                  pftCacheResync;
  PCERT_REVOCATION_CHAIN_PARA pChainPara;
} CERT_REVOCATION_PARA, *PCERT_REVOCATION_PARA;
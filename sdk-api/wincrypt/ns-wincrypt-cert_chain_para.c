typedef struct _CERT_CHAIN_PARA {
  DWORD                   cbSize;
  CERT_USAGE_MATCH        RequestedUsage;
  CERT_USAGE_MATCH        RequestedIssuancePolicy;
  DWORD                   dwUrlRetrievalTimeout;
  BOOL                    fCheckRevocationFreshnessTime;
  DWORD                   dwRevocationFreshnessTime;
  LPFILETIME              pftCacheResync;
  PCCERT_STRONG_SIGN_PARA pStrongSignPara;
  DWORD                   dwStrongSignFlags;
} CERT_CHAIN_PARA, *PCERT_CHAIN_PARA;
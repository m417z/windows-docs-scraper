typedef struct _CERT_CHAIN_CONTEXT {
  DWORD                cbSize;
  CERT_TRUST_STATUS    TrustStatus;
  DWORD                cChain;
  PCERT_SIMPLE_CHAIN   *rgpChain;
  DWORD                cLowerQualityChainContext;
  PCCERT_CHAIN_CONTEXT *rgpLowerQualityChainContext;
  BOOL                 fHasRevocationFreshnessTime;
  DWORD                dwRevocationFreshnessTime;
  DWORD                dwCreateFlags;
  GUID                 ChainId;
} CERT_CHAIN_CONTEXT, *PCERT_CHAIN_CONTEXT;
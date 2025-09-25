typedef struct _CERT_SIMPLE_CHAIN {
  DWORD                 cbSize;
  CERT_TRUST_STATUS     TrustStatus;
  DWORD                 cElement;
  PCERT_CHAIN_ELEMENT   *rgpElement;
  PCERT_TRUST_LIST_INFO pTrustListInfo;
  BOOL                  fHasRevocationFreshnessTime;
  DWORD                 dwRevocationFreshnessTime;
} CERT_SIMPLE_CHAIN, *PCERT_SIMPLE_CHAIN;
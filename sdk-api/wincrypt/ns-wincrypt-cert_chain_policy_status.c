typedef struct _CERT_CHAIN_POLICY_STATUS {
  DWORD cbSize;
  DWORD dwError;
  LONG  lChainIndex;
  LONG  lElementIndex;
  void  *pvExtraPolicyStatus;
} CERT_CHAIN_POLICY_STATUS, *PCERT_CHAIN_POLICY_STATUS;
typedef struct _CERT_CHAIN_POLICY_PARA {
  DWORD cbSize;
  DWORD dwFlags;
  void  *pvExtraPolicyPara;
} CERT_CHAIN_POLICY_PARA, *PCERT_CHAIN_POLICY_PARA;
typedef struct _CERT_REVOCATION_CRL_INFO {
  DWORD         cbSize;
  PCCRL_CONTEXT pBaseCrlContext;
  PCCRL_CONTEXT pDeltaCrlContext;
  PCRL_ENTRY    pCrlEntry;
  BOOL          fDeltaCrlEntry;
} CERT_REVOCATION_CRL_INFO, *PCERT_REVOCATION_CRL_INFO;
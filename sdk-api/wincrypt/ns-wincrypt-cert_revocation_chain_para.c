typedef struct _CERT_REVOCATION_CHAIN_PARA {
  DWORD            cbSize;
  HCERTCHAINENGINE hChainEngine;
  HCERTSTORE       hAdditionalStore;
  DWORD            dwChainFlags;
  DWORD            dwUrlRetrievalTimeout;
  LPFILETIME       pftCurrentTime;
  LPFILETIME       pftCacheResync;
  DWORD            cbMaxUrlRetrievalByteCount;
} CERT_REVOCATION_CHAIN_PARA, *PCERT_REVOCATION_CHAIN_PARA;
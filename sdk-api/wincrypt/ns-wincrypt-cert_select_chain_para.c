typedef struct _CERT_SELECT_CHAIN_PARA {
  HCERTCHAINENGINE hChainEngine;
  PFILETIME        pTime;
  HCERTSTORE       hAdditionalStore;
  PCERT_CHAIN_PARA pChainPara;
  DWORD            dwFlags;
} CERT_SELECT_CHAIN_PARA, *PCERT_SELECT_CHAIN_PARA;
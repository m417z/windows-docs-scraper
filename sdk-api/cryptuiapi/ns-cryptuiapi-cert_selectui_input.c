typedef struct {
  HCERTSTORE           hStore;
  PCCERT_CHAIN_CONTEXT *prgpChain;
  DWORD                cChain;
} CERT_SELECTUI_INPUT, *PCERT_SELECTUI_INPUT;
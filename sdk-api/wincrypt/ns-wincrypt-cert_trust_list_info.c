typedef struct _CERT_TRUST_LIST_INFO {
  DWORD         cbSize;
  PCTL_ENTRY    pCtlEntry;
  PCCTL_CONTEXT pCtlContext;
} CERT_TRUST_LIST_INFO, *PCERT_TRUST_LIST_INFO;
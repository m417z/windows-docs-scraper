typedef struct _CERT_CREATE_CONTEXT_PARA {
  DWORD                             cbSize;
  PFN_CRYPT_FREE                    pfnFree;
  void                              *pvFree;
  PFN_CERT_CREATE_CONTEXT_SORT_FUNC pfnSort;
  void                              *pvSort;
} CERT_CREATE_CONTEXT_PARA, *PCERT_CREATE_CONTEXT_PARA;
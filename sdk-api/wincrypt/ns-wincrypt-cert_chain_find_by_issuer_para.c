typedef struct _CERT_CHAIN_FIND_BY_ISSUER_PARA {
  DWORD                                  cbSize;
  LPCSTR                                 pszUsageIdentifier;
  DWORD                                  dwKeySpec;
  DWORD                                  dwAcquirePrivateKeyFlags;
  DWORD                                  cIssuer;
  CERT_NAME_BLOB                         *rgIssuer;
  PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK pfnFindCallback;
  void                                   *pvFindArg;
  DWORD                                  *pdwIssuerChainIndex;
  DWORD                                  *pdwIssuerElementIndex;
} CERT_CHAIN_FIND_ISSUER_PARA, *PCERT_CHAIN_FIND_ISSUER_PARA, CERT_CHAIN_FIND_BY_ISSUER_PARA, *PCERT_CHAIN_FIND_BY_ISSUER_PARA;
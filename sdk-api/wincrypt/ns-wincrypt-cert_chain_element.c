typedef struct _CERT_CHAIN_ELEMENT {
  DWORD                 cbSize;
  PCCERT_CONTEXT        pCertContext;
  CERT_TRUST_STATUS     TrustStatus;
  PCERT_REVOCATION_INFO pRevocationInfo;
  PCERT_ENHKEY_USAGE    pIssuanceUsage;
  PCERT_ENHKEY_USAGE    pApplicationUsage;
  LPCWSTR               pwszExtendedErrorInfo;
} CERT_CHAIN_ELEMENT, *PCERT_CHAIN_ELEMENT;
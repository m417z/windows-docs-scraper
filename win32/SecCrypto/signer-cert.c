typedef struct _SIGNER_CERT {
  DWORD cbSize;
  DWORD dwCertChoice;
  union {
    LPCWSTR                pwszSpcFile;
    SIGNER_CERT_STORE_INFO *pCertStoreInfo;
    SIGNER_SPC_CHAIN_INFO  *pSpcChainInfo;
  };
  HWND  hwnd;
} SIGNER_CERT, *PSIGNER_CERT;
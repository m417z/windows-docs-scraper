typedef struct _CRYPT_TIMESTAMP_PARA {
  LPCSTR             pszTSAPolicyId;
  BOOL               fRequestCerts;
  CRYPT_INTEGER_BLOB Nonce;
  DWORD              cExtension;
  PCERT_EXTENSION    rgExtension;
} CRYPT_TIMESTAMP_PARA, *PCRYPT_TIMESTAMP_PARA;
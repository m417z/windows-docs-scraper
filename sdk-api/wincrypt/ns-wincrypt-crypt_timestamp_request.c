typedef struct _CRYPT_TIMESTAMP_REQUEST {
  DWORD                      dwVersion;
  CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
  CRYPT_DER_BLOB             HashedMessage;
  LPSTR                      pszTSAPolicyId;
  CRYPT_INTEGER_BLOB         Nonce;
  BOOL                       fCertReq;
  DWORD                      cExtension;
  PCERT_EXTENSION            rgExtension;
} CRYPT_TIMESTAMP_REQUEST, *PCRYPT_TIMESTAMP_REQUEST;
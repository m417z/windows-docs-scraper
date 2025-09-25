typedef struct _CRYPT_TIMESTAMP_INFO {
  DWORD                      dwVersion;
  LPSTR                      pszTSAPolicyId;
  CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
  CRYPT_DER_BLOB             HashedMessage;
  CRYPT_INTEGER_BLOB         SerialNumber;
  FILETIME                   ftTime;
  PCRYPT_TIMESTAMP_ACCURACY  pvAccuracy;
  BOOL                       fOrdering;
  CRYPT_DER_BLOB             Nonce;
  CRYPT_DER_BLOB             Tsa;
  DWORD                      cExtension;
  PCERT_EXTENSION            rgExtension;
} CRYPT_TIMESTAMP_INFO, *PCRYPT_TIMESTAMP_INFO;
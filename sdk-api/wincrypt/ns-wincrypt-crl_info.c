typedef struct _CRL_INFO {
  DWORD                      dwVersion;
  CRYPT_ALGORITHM_IDENTIFIER SignatureAlgorithm;
  CERT_NAME_BLOB             Issuer;
  FILETIME                   ThisUpdate;
  FILETIME                   NextUpdate;
  DWORD                      cCRLEntry;
  PCRL_ENTRY                 rgCRLEntry;
  DWORD                      cExtension;
  PCERT_EXTENSION            rgExtension;
} CRL_INFO, *PCRL_INFO;
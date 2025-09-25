typedef struct _CERT_KEY_CONTEXT {
  DWORD cbSize;
  union {
    HCRYPTPROV        hCryptProv;
    NCRYPT_KEY_HANDLE hNCryptKey;
  } DUMMYUNIONNAME;
  DWORD dwKeySpec;
} CERT_KEY_CONTEXT, *PCERT_KEY_CONTEXT;
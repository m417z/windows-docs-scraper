typedef struct _CRYPT_KEY_PROV_INFO {
  LPWSTR                pwszContainerName;
  LPWSTR                pwszProvName;
  DWORD                 dwProvType;
  DWORD                 dwFlags;
  DWORD                 cProvParam;
  PCRYPT_KEY_PROV_PARAM rgProvParam;
  DWORD                 dwKeySpec;
} CRYPT_KEY_PROV_INFO, *PCRYPT_KEY_PROV_INFO;
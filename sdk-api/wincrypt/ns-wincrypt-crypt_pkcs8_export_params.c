typedef struct _CRYPT_PKCS8_EXPORT_PARAMS {
  HCRYPTPROV                      hCryptProv;
  DWORD                           dwKeySpec;
  LPSTR                           pszPrivateKeyObjId;
  PCRYPT_ENCRYPT_PRIVATE_KEY_FUNC pEncryptPrivateKeyFunc;
  LPVOID                          pVoidEncryptFunc;
} CRYPT_PKCS8_EXPORT_PARAMS, *PCRYPT_PKCS8_EXPORT_PARAMS;
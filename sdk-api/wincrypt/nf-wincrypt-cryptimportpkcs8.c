BOOL CryptImportPKCS8(
  [in]            CRYPT_PKCS8_IMPORT_PARAMS sPrivateKeyAndParams,
  [in]            DWORD                     dwFlags,
  [out, optional] HCRYPTPROV                *phCryptProv,
  [in, optional]  void                      *pvAuxInfo
);
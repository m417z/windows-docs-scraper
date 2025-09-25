BOOL CryptImportPublicKeyInfoEx2(
  [in]  DWORD                 dwCertEncodingType,
  [in]  PCERT_PUBLIC_KEY_INFO pInfo,
  [in]  DWORD                 dwFlags,
  [in]  void                  *pvAuxInfo,
  [out] BCRYPT_KEY_HANDLE     *phKey
);
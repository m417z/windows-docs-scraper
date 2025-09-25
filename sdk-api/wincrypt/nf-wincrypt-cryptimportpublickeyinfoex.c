BOOL CryptImportPublicKeyInfoEx(
  [in]  HCRYPTPROV            hCryptProv,
  [in]  DWORD                 dwCertEncodingType,
  [in]  PCERT_PUBLIC_KEY_INFO pInfo,
  [in]  ALG_ID                aiKeyAlg,
  [in]  DWORD                 dwFlags,
  [in]  void                  *pvAuxInfo,
  [out] HCRYPTKEY             *phKey
);
BOOL CryptImportPublicKeyInfo(
  [in]  HCRYPTPROV            hCryptProv,
  [in]  DWORD                 dwCertEncodingType,
  [in]  PCERT_PUBLIC_KEY_INFO pInfo,
  [out] HCRYPTKEY             *phKey
);
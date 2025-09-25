BOOL CryptExportPublicKeyInfoEx(
  [in]      HCRYPTPROV_OR_NCRYPT_KEY_HANDLE hCryptProvOrNCryptKey,
  [in]      DWORD                           dwKeySpec,
  [in]      DWORD                           dwCertEncodingType,
  [in]      LPSTR                           pszPublicKeyObjId,
  [in]      DWORD                           dwFlags,
  [in]      void                            *pvAuxInfo,
  [out]     PCERT_PUBLIC_KEY_INFO           pInfo,
  [in, out] DWORD                           *pcbInfo
);
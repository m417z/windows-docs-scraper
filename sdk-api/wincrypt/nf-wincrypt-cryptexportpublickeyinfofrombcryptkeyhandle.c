BOOL CryptExportPublicKeyInfoFromBCryptKeyHandle(
  [in]            BCRYPT_KEY_HANDLE     hBCryptKey,
  [in]            DWORD                 dwCertEncodingType,
  [in, optional]  LPSTR                 pszPublicKeyObjId,
  [in]            DWORD                 dwFlags,
  [in, optional]  void                  *pvAuxInfo,
  [out, optional] PCERT_PUBLIC_KEY_INFO pInfo,
  [in, out]       DWORD                 *pcbInfo
);
BOOL CryptHashPublicKeyInfo(
  [in]      HCRYPTPROV_LEGACY     hCryptProv,
  [in]      ALG_ID                Algid,
  [in]      DWORD                 dwFlags,
  [in]      DWORD                 dwCertEncodingType,
  [in]      PCERT_PUBLIC_KEY_INFO pInfo,
  [out]     BYTE                  *pbComputedHash,
  [in, out] DWORD                 *pcbComputedHash
);
BOOL CryptHashCertificate(
  [in]      HCRYPTPROV_LEGACY hCryptProv,
  [in]      ALG_ID            Algid,
  [in]      DWORD             dwFlags,
  [in]      const BYTE        *pbEncoded,
  [in]      DWORD             cbEncoded,
  [out]     BYTE              *pbComputedHash,
  [in, out] DWORD             *pcbComputedHash
);
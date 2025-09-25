BOOL CryptHashToBeSigned(
  [in]      HCRYPTPROV_LEGACY hCryptProv,
  [in]      DWORD             dwCertEncodingType,
  [in]      const BYTE        *pbEncoded,
  [in]      DWORD             cbEncoded,
  [out]     BYTE              *pbComputedHash,
  [in, out] DWORD             *pcbComputedHash
);
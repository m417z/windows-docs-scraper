BOOL CryptVerifyCertificateSignature(
  [in] HCRYPTPROV_LEGACY     hCryptProv,
  [in] DWORD                 dwCertEncodingType,
  [in] const BYTE            *pbEncoded,
  [in] DWORD                 cbEncoded,
  [in] PCERT_PUBLIC_KEY_INFO pPublicKey
);
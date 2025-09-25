BOOL CryptSignAndEncodeCertificate(
  [in]      BCRYPT_KEY_HANDLE           hBCryptKey,
  [in]      DWORD                       dwKeySpec,
  [in]      DWORD                       dwCertEncodingType,
  [in]      LPCSTR                      lpszStructType,
  [in]      const void                  *pvStructInfo,
  [in]      PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
  [in]      const void                  *pvHashAuxInfo,
  [out]     BYTE                        *pbEncoded,
  [in, out] DWORD                       *pcbEncoded
);
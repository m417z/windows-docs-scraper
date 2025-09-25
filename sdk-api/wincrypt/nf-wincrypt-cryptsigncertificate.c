BOOL CryptSignCertificate(
  [in]      BCRYPT_KEY_HANDLE           hBCryptKey,
  [in]      DWORD                       dwKeySpec,
  [in]      DWORD                       dwCertEncodingType,
  [in]      const BYTE                  *pbEncodedToBeSigned,
  [in]      DWORD                       cbEncodedToBeSigned,
  [in]      PCRYPT_ALGORITHM_IDENTIFIER pSignatureAlgorithm,
  [in]      const void                  *pvHashAuxInfo,
  [out]     BYTE                        *pbSignature,
  [in, out] DWORD                       *pcbSignature
);
BOOL CryptVerifyMessageSignatureWithKey(
  [in]      PCRYPT_KEY_VERIFY_MESSAGE_PARA pVerifyPara,
  [in]      PCERT_PUBLIC_KEY_INFO          pPublicKeyInfo,
  [in]      const BYTE                     *pbSignedBlob,
  [in]      DWORD                          cbSignedBlob,
  [out]     BYTE                           *pbDecoded,
  [in, out] DWORD                          *pcbDecoded
);
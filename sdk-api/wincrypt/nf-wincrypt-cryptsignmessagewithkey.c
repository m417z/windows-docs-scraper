BOOL CryptSignMessageWithKey(
  [in]      PCRYPT_KEY_SIGN_MESSAGE_PARA pSignPara,
  [in]      const BYTE                   *pbToBeSigned,
  [in]      DWORD                        cbToBeSigned,
  [out]     BYTE                         *pbSignedBlob,
  [in, out] DWORD                        *pcbSignedBlob
);
BOOL CryptSignMessage(
  [in]      PCRYPT_SIGN_MESSAGE_PARA pSignPara,
  [in]      BOOL                     fDetachedSignature,
  [in]      DWORD                    cToBeSigned,
  [in]      const BYTE * []          rgpbToBeSigned,
  [in]      DWORD []                 rgcbToBeSigned,
  [out]     BYTE                     *pbSignedBlob,
  [in, out] DWORD                    *pcbSignedBlob
);
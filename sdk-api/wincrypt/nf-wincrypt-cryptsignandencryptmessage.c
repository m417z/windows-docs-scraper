BOOL CryptSignAndEncryptMessage(
  [in]      PCRYPT_SIGN_MESSAGE_PARA    pSignPara,
  [in]      PCRYPT_ENCRYPT_MESSAGE_PARA pEncryptPara,
  [in]      DWORD                       cRecipientCert,
  [in]      PCCERT_CONTEXT []           rgpRecipientCert,
  [in]      const BYTE                  *pbToBeSignedAndEncrypted,
  [in]      DWORD                       cbToBeSignedAndEncrypted,
  [out]     BYTE                        *pbSignedAndEncryptedBlob,
  [in, out] DWORD                       *pcbSignedAndEncryptedBlob
);
BOOL CryptEncryptMessage(
  [in]      PCRYPT_ENCRYPT_MESSAGE_PARA pEncryptPara,
  [in]      DWORD                       cRecipientCert,
  [in]      PCCERT_CONTEXT []           rgpRecipientCert,
  [in]      const BYTE                  *pbToBeEncrypted,
  [in]      DWORD                       cbToBeEncrypted,
  [out]     BYTE                        *pbEncryptedBlob,
  [in, out] DWORD                       *pcbEncryptedBlob
);
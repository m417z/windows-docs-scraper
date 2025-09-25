BOOL CryptDecryptMessage(
  [in]                PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara,
  [in]                const BYTE                  *pbEncryptedBlob,
  [in]                DWORD                       cbEncryptedBlob,
  [out, optional]     BYTE                        *pbDecrypted,
  [in, out, optional] DWORD                       *pcbDecrypted,
  [out, optional]     PCCERT_CONTEXT              *ppXchgCert
);
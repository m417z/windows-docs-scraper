BOOL CryptDecryptAndVerifyMessageSignature(
  [in]                PCRYPT_DECRYPT_MESSAGE_PARA pDecryptPara,
  [in]                PCRYPT_VERIFY_MESSAGE_PARA  pVerifyPara,
  [in]                DWORD                       dwSignerIndex,
  [in]                const BYTE                  *pbEncryptedBlob,
  [in]                DWORD                       cbEncryptedBlob,
  [out, optional]     BYTE                        *pbDecrypted,
  [in, out, optional] DWORD                       *pcbDecrypted,
  [out, optional]     PCCERT_CONTEXT              *ppXchgCert,
  [out, optional]     PCCERT_CONTEXT              *ppSignerCert
);
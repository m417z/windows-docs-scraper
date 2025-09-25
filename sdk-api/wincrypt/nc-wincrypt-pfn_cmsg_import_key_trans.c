PFN_CMSG_IMPORT_KEY_TRANS PfnCmsgImportKeyTrans;

BOOL PfnCmsgImportKeyTrans(
  [in]  PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm,
  [in]  PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA pKeyTransDecryptPara,
  [in]  DWORD dwFlags,
        void *pvReserved,
  [out] HCRYPTKEY *phContentEncryptKey
)
{...}
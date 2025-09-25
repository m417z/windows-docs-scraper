PFN_CMSG_IMPORT_KEY_AGREE PfnCmsgImportKeyAgree;

BOOL PfnCmsgImportKeyAgree(
  [in]  PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm,
  [in]  PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA pKeyAgreeDecryptPara,
  [in]  DWORD dwFlags,
        void *pvReserved,
  [out] HCRYPTKEY *phContentEncryptKey
)
{...}
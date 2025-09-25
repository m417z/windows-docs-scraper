PFN_CMSG_IMPORT_MAIL_LIST PfnCmsgImportMailList;

BOOL PfnCmsgImportMailList(
  [in]  PCRYPT_ALGORITHM_IDENTIFIER pContentEncryptionAlgorithm,
  [in]  PCMSG_CTRL_MAIL_LIST_DECRYPT_PARA pMailListDecryptPara,
  [in]  DWORD dwFlags,
        void *pvReserved,
  [out] HCRYPTKEY *phContentEncryptKey
)
{...}
PFN_CMSG_CNG_IMPORT_CONTENT_ENCRYPT_KEY PfnCmsgCngImportContentEncryptKey;

BOOL PfnCmsgCngImportContentEncryptKey(
  [in, out] PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo,
  [in]      DWORD dwFlags,
            void *pvReserved
)
{...}
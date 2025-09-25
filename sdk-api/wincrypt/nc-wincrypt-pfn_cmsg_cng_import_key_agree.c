PFN_CMSG_CNG_IMPORT_KEY_AGREE PfnCmsgCngImportKeyAgree;

BOOL PfnCmsgCngImportKeyAgree(
  [in, out] PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo,
  [in]      PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA pKeyAgreeDecryptPara,
  [in]      DWORD dwFlags,
            void *pvReserved
)
{...}
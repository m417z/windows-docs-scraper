PFN_CMSG_CNG_IMPORT_KEY_TRANS PfnCmsgCngImportKeyTrans;

BOOL PfnCmsgCngImportKeyTrans(
  [in, out] PCMSG_CNG_CONTENT_DECRYPT_INFO pCNGContentDecryptInfo,
  [in]      PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA pKeyTransDecryptPara,
  [in]      DWORD dwFlags,
            void *pvReserved
)
{...}
PFN_CMSG_EXPORT_KEY_AGREE PfnCmsgExportKeyAgree;

BOOL PfnCmsgExportKeyAgree(
  [in]      PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo,
  [in]      PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO pKeyAgreeEncodeInfo,
  [in, out] PCMSG_KEY_AGREE_ENCRYPT_INFO pKeyAgreeEncryptInfo,
  [in]      DWORD dwFlags,
            void *pvReserved
)
{...}
PFN_CMSG_EXPORT_KEY_TRANS PfnCmsgExportKeyTrans;

BOOL PfnCmsgExportKeyTrans(
  [in]      PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo,
  [in]      PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO pKeyTransEncodeInfo,
  [in, out] PCMSG_KEY_TRANS_ENCRYPT_INFO pKeyTransEncryptInfo,
  [in]      DWORD dwFlags,
            void *pvReserved
)
{...}
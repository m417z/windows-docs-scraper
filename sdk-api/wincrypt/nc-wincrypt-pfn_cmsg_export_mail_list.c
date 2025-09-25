PFN_CMSG_EXPORT_MAIL_LIST PfnCmsgExportMailList;

BOOL PfnCmsgExportMailList(
  [in]      PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo,
  [in]      PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO pMailListEncodeInfo,
  [in, out] PCMSG_MAIL_LIST_ENCRYPT_INFO pMailListEncryptInfo,
  [in]      DWORD dwFlags,
            void *pvReserved
)
{...}
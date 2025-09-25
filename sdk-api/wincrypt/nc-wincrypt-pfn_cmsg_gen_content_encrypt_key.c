PFN_CMSG_GEN_CONTENT_ENCRYPT_KEY PfnCmsgGenContentEncryptKey;

BOOL PfnCmsgGenContentEncryptKey(
  [in, out] PCMSG_CONTENT_ENCRYPT_INFO pContentEncryptInfo,
  [in]      DWORD dwFlags,
            void *pvReserved
)
{...}
typedef struct _CMSG_CTRL_DECRYPT_PARA {
  DWORD cbSize;
  union {
    HCRYPTPROV        hCryptProv;
    NCRYPT_KEY_HANDLE hNCryptKey;
  } DUMMYUNIONNAME;
  DWORD dwKeySpec;
  DWORD dwRecipientIndex;
} CMSG_CTRL_DECRYPT_PARA, *PCMSG_CTRL_DECRYPT_PARA;
typedef struct _CMSG_CTRL_KEY_TRANS_DECRYPT_PARA {
  DWORD                          cbSize;
  union {
    HCRYPTPROV        hCryptProv;
    NCRYPT_KEY_HANDLE hNCryptKey;
  } DUMMYUNIONNAME;
  DWORD                          dwKeySpec;
  PCMSG_KEY_TRANS_RECIPIENT_INFO pKeyTrans;
  DWORD                          dwRecipientIndex;
} CMSG_CTRL_KEY_TRANS_DECRYPT_PARA, *PCMSG_CTRL_KEY_TRANS_DECRYPT_PARA;
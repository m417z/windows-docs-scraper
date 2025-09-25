typedef struct _CMSG_CTRL_MAIL_LIST_DECRYPT_PARA {
  DWORD                          cbSize;
  HCRYPTPROV                     hCryptProv;
  PCMSG_MAIL_LIST_RECIPIENT_INFO pMailList;
  DWORD                          dwRecipientIndex;
  DWORD                          dwKeyChoice;
  union {
    HCRYPTKEY hKeyEncryptionKey;
    void      *pvKeyEncryptionKey;
  } DUMMYUNIONNAME;
} CMSG_CTRL_MAIL_LIST_DECRYPT_PARA, *PCMSG_CTRL_MAIL_LIST_DECRYPT_PARA;
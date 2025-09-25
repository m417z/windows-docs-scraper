typedef struct _CMSG_CTRL_KEY_AGREE_DECRYPT_PARA {
  DWORD                          cbSize;
  union {
    HCRYPTPROV        hCryptProv;
    NCRYPT_KEY_HANDLE hNCryptKey;
  } DUMMYUNIONNAME;
  DWORD                          dwKeySpec;
  PCMSG_KEY_AGREE_RECIPIENT_INFO pKeyAgree;
  DWORD                          dwRecipientIndex;
  DWORD                          dwRecipientEncryptedKeyIndex;
  CRYPT_BIT_BLOB                 OriginatorPublicKey;
} CMSG_CTRL_KEY_AGREE_DECRYPT_PARA, *PCMSG_CTRL_KEY_AGREE_DECRYPT_PARA;
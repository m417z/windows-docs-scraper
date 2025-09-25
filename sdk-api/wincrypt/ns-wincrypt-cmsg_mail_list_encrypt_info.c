typedef struct _CMSG_MAIL_LIST_ENCRYPT_INFO {
  DWORD                      cbSize;
  DWORD                      dwRecipientIndex;
  CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
  CRYPT_DATA_BLOB            EncryptedKey;
  DWORD                      dwFlags;
} CMSG_MAIL_LIST_ENCRYPT_INFO, *PCMSG_MAIL_LIST_ENCRYPT_INFO;
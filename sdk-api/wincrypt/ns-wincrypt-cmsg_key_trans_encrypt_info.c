typedef struct _CMSG_KEY_TRANS_ENCRYPT_INFO {
  DWORD                      cbSize;
  DWORD                      dwRecipientIndex;
  CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
  CRYPT_DATA_BLOB            EncryptedKey;
  DWORD                      dwFlags;
} CMSG_KEY_TRANS_ENCRYPT_INFO, *PCMSG_KEY_TRANS_ENCRYPT_INFO;
typedef struct _CMSG_KEY_TRANS_RECIPIENT_INFO {
  DWORD                      dwVersion;
  CERT_ID                    RecipientId;
  CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
  CRYPT_DATA_BLOB            EncryptedKey;
} CMSG_KEY_TRANS_RECIPIENT_INFO, *PCMSG_KEY_TRANS_RECIPIENT_INFO;
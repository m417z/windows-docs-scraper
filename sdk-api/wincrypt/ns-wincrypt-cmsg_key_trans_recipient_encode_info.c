typedef struct _CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO {
  DWORD                      cbSize;
  CRYPT_ALGORITHM_IDENTIFIER KeyEncryptionAlgorithm;
  void                       *pvKeyEncryptionAuxInfo;
  HCRYPTPROV_LEGACY          hCryptProv;
  CRYPT_BIT_BLOB             RecipientPublicKey;
  CERT_ID                    RecipientId;
} CMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO, *PCMSG_KEY_TRANS_RECIPIENT_ENCODE_INFO;
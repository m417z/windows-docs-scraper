typedef struct _CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO {
  DWORD                                     cbSize;
  CRYPT_ALGORITHM_IDENTIFIER                KeyEncryptionAlgorithm;
  void                                      *pvKeyEncryptionAuxInfo;
  CRYPT_ALGORITHM_IDENTIFIER                KeyWrapAlgorithm;
  void                                      *pvKeyWrapAuxInfo;
  HCRYPTPROV_LEGACY                         hCryptProv;
  DWORD                                     dwKeySpec;
  DWORD                                     dwKeyChoice;
  union {
    PCRYPT_ALGORITHM_IDENTIFIER pEphemeralAlgorithm;
    PCERT_ID                    pSenderId;
  } DUMMYUNIONNAME;
  CRYPT_DATA_BLOB                           UserKeyingMaterial;
  DWORD                                     cRecipientEncryptedKeys;
  PCMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO *rgpRecipientEncryptedKeys;
} CMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO, *PCMSG_KEY_AGREE_RECIPIENT_ENCODE_INFO;
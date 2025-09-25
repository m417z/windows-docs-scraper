typedef struct _CMSG_KEY_AGREE_RECIPIENT_INFO {
  DWORD                              dwVersion;
  DWORD                              dwOriginatorChoice;
  union {
    CERT_ID              OriginatorCertId;
    CERT_PUBLIC_KEY_INFO OriginatorPublicKeyInfo;
  } DUMMYUNIONNAME;
  CRYPT_DATA_BLOB                    UserKeyingMaterial;
  CRYPT_ALGORITHM_IDENTIFIER         KeyEncryptionAlgorithm;
  DWORD                              cRecipientEncryptedKeys;
  PCMSG_RECIPIENT_ENCRYPTED_KEY_INFO *rgpRecipientEncryptedKeys;
} CMSG_KEY_AGREE_RECIPIENT_INFO, *PCMSG_KEY_AGREE_RECIPIENT_INFO;
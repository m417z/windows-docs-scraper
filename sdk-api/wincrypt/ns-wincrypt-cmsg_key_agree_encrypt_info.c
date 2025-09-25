typedef struct _CMSG_KEY_AGREE_ENCRYPT_INFO {
  DWORD                            cbSize;
  DWORD                            dwRecipientIndex;
  CRYPT_ALGORITHM_IDENTIFIER       KeyEncryptionAlgorithm;
  CRYPT_DATA_BLOB                  UserKeyingMaterial;
  DWORD                            dwOriginatorChoice;
  union {
    CERT_ID              OriginatorCertId;
    CERT_PUBLIC_KEY_INFO OriginatorPublicKeyInfo;
  } DUMMYUNIONNAME;
  DWORD                            cKeyAgreeKeyEncryptInfo;
  PCMSG_KEY_AGREE_KEY_ENCRYPT_INFO *rgpKeyAgreeKeyEncryptInfo;
  DWORD                            dwFlags;
} CMSG_KEY_AGREE_ENCRYPT_INFO, *PCMSG_KEY_AGREE_ENCRYPT_INFO;
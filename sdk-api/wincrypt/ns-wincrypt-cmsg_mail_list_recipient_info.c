typedef struct _CMSG_MAIL_LIST_RECIPIENT_INFO {
  DWORD                       dwVersion;
  CRYPT_DATA_BLOB             KeyId;
  CRYPT_ALGORITHM_IDENTIFIER  KeyEncryptionAlgorithm;
  CRYPT_DATA_BLOB             EncryptedKey;
  FILETIME                    Date;
  PCRYPT_ATTRIBUTE_TYPE_VALUE pOtherAttr;
} CMSG_MAIL_LIST_RECIPIENT_INFO, *PCMSG_MAIL_LIST_RECIPIENT_INFO;
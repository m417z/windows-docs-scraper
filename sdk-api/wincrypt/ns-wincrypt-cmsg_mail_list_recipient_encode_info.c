typedef struct _CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO {
  DWORD                       cbSize;
  CRYPT_ALGORITHM_IDENTIFIER  KeyEncryptionAlgorithm;
  void                        *pvKeyEncryptionAuxInfo;
  HCRYPTPROV                  hCryptProv;
  DWORD                       dwKeyChoice;
  union {
    HCRYPTKEY hKeyEncryptionKey;
    void      *pvKeyEncryptionKey;
  } DUMMYUNIONNAME;
  CRYPT_DATA_BLOB             KeyId;
  FILETIME                    Date;
  PCRYPT_ATTRIBUTE_TYPE_VALUE pOtherAttr;
} CMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO, *PCMSG_MAIL_LIST_RECIPIENT_ENCODE_INFO;
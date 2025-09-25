typedef struct _CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO {
  DWORD                       cbSize;
  CRYPT_BIT_BLOB              RecipientPublicKey;
  CERT_ID                     RecipientId;
  FILETIME                    Date;
  PCRYPT_ATTRIBUTE_TYPE_VALUE pOtherAttr;
} CMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO, *PCMSG_RECIPIENT_ENCRYPTED_KEY_ENCODE_INFO;
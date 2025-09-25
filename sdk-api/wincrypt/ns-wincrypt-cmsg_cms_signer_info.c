typedef struct _CMSG_CMS_SIGNER_INFO {
  DWORD                      dwVersion;
  CERT_ID                    SignerId;
  CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
  CRYPT_ALGORITHM_IDENTIFIER HashEncryptionAlgorithm;
  CRYPT_DATA_BLOB            EncryptedHash;
  CRYPT_ATTRIBUTES           AuthAttrs;
  CRYPT_ATTRIBUTES           UnauthAttrs;
} CMSG_CMS_SIGNER_INFO, *PCMSG_CMS_SIGNER_INFO;
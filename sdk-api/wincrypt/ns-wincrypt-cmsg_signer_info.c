typedef struct _CMSG_SIGNER_INFO {
  DWORD                      dwVersion;
  CERT_NAME_BLOB             Issuer;
  CRYPT_INTEGER_BLOB         SerialNumber;
  CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
  CRYPT_ALGORITHM_IDENTIFIER HashEncryptionAlgorithm;
  CRYPT_DATA_BLOB            EncryptedHash;
  CRYPT_ATTRIBUTES           AuthAttrs;
  CRYPT_ATTRIBUTES           UnauthAttrs;
} CMSG_SIGNER_INFO, *PCMSG_SIGNER_INFO;
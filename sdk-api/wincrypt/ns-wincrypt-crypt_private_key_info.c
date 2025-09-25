typedef struct _CRYPT_PRIVATE_KEY_INFO {
  DWORD                      Version;
  CRYPT_ALGORITHM_IDENTIFIER Algorithm;
  CRYPT_DER_BLOB             PrivateKey;
  PCRYPT_ATTRIBUTES          pAttributes;
} CRYPT_PRIVATE_KEY_INFO, *PCRYPT_PRIVATE_KEY_INFO;
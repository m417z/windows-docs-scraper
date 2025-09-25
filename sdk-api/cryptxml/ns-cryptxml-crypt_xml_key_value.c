typedef struct _CRYPT_XML_KEY_VALUE {
  DWORD dwType;
  union {
    CRYPT_XML_KEY_DSA_KEY_VALUE   DSAKeyValue;
    CRYPT_XML_KEY_RSA_KEY_VALUE   RSAKeyValue;
    CRYPT_XML_KEY_ECDSA_KEY_VALUE ECDSAKeyValue;
    CRYPT_XML_BLOB                Custom;
  };
} CRYPT_XML_KEY_VALUE;
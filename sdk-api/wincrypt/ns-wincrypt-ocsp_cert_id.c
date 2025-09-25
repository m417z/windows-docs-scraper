typedef struct _OCSP_CERT_ID {
  CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
  CRYPT_HASH_BLOB            IssuerNameHash;
  CRYPT_HASH_BLOB            IssuerKeyHash;
  CRYPT_INTEGER_BLOB         SerialNumber;
} OCSP_CERT_ID, *POCSP_CERT_ID;
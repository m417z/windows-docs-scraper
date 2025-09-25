typedef struct _CERT_HASHED_URL {
  CRYPT_ALGORITHM_IDENTIFIER HashAlgorithm;
  CRYPT_HASH_BLOB            Hash;
  LPWSTR                     pwszUrl;
} CERT_HASHED_URL, *PCERT_HASHED_URL;
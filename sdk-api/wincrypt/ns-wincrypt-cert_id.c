typedef struct _CERT_ID {
  DWORD dwIdChoice;
  union {
    CERT_ISSUER_SERIAL_NUMBER IssuerSerialNumber;
    CRYPT_HASH_BLOB           KeyId;
    CRYPT_HASH_BLOB           HashId;
  } DUMMYUNIONNAME;
} CERT_ID, *PCERT_ID;
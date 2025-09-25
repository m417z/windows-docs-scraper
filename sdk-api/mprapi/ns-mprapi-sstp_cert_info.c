typedef struct _SSTP_CERT_INFO {
  BOOL            isDefault;
  CRYPT_HASH_BLOB certBlob;
} SSTP_CERT_INFO, *PSSTP_CERT_INFO;
typedef struct _ENCRYPTION_CERTIFICATE_HASH {
  DWORD          cbTotalLength;
  SID            *pUserSid;
  PEFS_HASH_BLOB pHash;
  LPWSTR         lpDisplayInformation;
} ENCRYPTION_CERTIFICATE_HASH, *PENCRYPTION_CERTIFICATE_HASH;
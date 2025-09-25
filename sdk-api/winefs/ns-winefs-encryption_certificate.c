typedef struct _ENCRYPTION_CERTIFICATE {
  DWORD                 cbTotalLength;
  SID                   *pUserSid;
  PEFS_CERTIFICATE_BLOB pCertBlob;
} ENCRYPTION_CERTIFICATE, *PENCRYPTION_CERTIFICATE;
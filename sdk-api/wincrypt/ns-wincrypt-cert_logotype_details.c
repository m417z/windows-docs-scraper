typedef struct _CERT_LOGOTYPE_DETAILS {
  LPWSTR           pwszMimeType;
  DWORD            cHashedUrl;
  PCERT_HASHED_URL rgHashedUrl;
} CERT_LOGOTYPE_DETAILS, *PCERT_LOGOTYPE_DETAILS;
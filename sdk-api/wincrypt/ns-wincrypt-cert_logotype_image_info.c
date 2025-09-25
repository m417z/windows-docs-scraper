typedef struct _CERT_LOGOTYPE_IMAGE_INFO {
  DWORD  dwLogotypeImageInfoChoice;
  DWORD  dwFileSize;
  DWORD  dwXSize;
  DWORD  dwYSize;
  DWORD  dwLogotypeImageResolutionChoice;
  union {
    DWORD dwNumBits;
    DWORD dwTableSize;
  } DUMMYUNIONNAME;
  LPWSTR pwszLanguage;
} CERT_LOGOTYPE_IMAGE_INFO, *PCERT_LOGOTYPE_IMAGE_INFO;
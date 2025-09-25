typedef struct _OCSP_REQUEST_INFO {
  DWORD                dwVersion;
  PCERT_ALT_NAME_ENTRY pRequestorName;
  DWORD                cRequestEntry;
  POCSP_REQUEST_ENTRY  rgRequestEntry;
  DWORD                cExtension;
  PCERT_EXTENSION      rgExtension;
} OCSP_REQUEST_INFO, *POCSP_REQUEST_INFO;
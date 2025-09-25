typedef struct _OCSP_REQUEST_ENTRY {
  OCSP_CERT_ID    CertId;
  DWORD           cExtension;
  PCERT_EXTENSION rgExtension;
} OCSP_REQUEST_ENTRY, *POCSP_REQUEST_ENTRY;
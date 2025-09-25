typedef struct _OCSP_BASIC_RESPONSE_ENTRY {
  OCSP_CERT_ID    CertId;
  DWORD           dwCertStatus;
  union {
    POCSP_BASIC_REVOKED_INFO pRevokedInfo;
  } DUMMYUNIONNAME;
  FILETIME        ThisUpdate;
  FILETIME        NextUpdate;
  DWORD           cExtension;
  PCERT_EXTENSION rgExtension;
} OCSP_BASIC_RESPONSE_ENTRY, *POCSP_BASIC_RESPONSE_ENTRY;
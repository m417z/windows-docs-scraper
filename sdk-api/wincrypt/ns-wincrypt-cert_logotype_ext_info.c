typedef struct _CERT_LOGOTYPE_EXT_INFO {
  DWORD                     cCommunityLogo;
  PCERT_LOGOTYPE_INFO       rgCommunityLogo;
  PCERT_LOGOTYPE_INFO       pIssuerLogo;
  PCERT_LOGOTYPE_INFO       pSubjectLogo;
  DWORD                     cOtherLogo;
  PCERT_OTHER_LOGOTYPE_INFO rgOtherLogo;
} CERT_LOGOTYPE_EXT_INFO, *PCERT_LOGOTYPE_EXT_INFO;
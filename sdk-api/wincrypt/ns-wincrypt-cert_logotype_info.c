typedef struct _CERT_LOGOTYPE_INFO {
  DWORD dwLogotypeInfoChoice;
  union {
    PCERT_LOGOTYPE_DATA      pLogotypeDirectInfo;
    PCERT_LOGOTYPE_REFERENCE pLogotypeIndirectInfo;
  } DUMMYUNIONNAME;
} CERT_LOGOTYPE_INFO, *PCERT_LOGOTYPE_INFO;
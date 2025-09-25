typedef struct _CERT_STORE_PROV_FIND_INFO {
  DWORD      cbSize;
  DWORD      dwMsgAndCertEncodingType;
  DWORD      dwFindFlags;
  DWORD      dwFindType;
  const void *pvFindPara;
} CERT_STORE_PROV_FIND_INFO, *PCERT_STORE_PROV_FIND_INFO;
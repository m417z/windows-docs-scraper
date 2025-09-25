typedef struct _CMC_ADD_ATTRIBUTES_INFO {
  DWORD            dwCmcDataReference;
  DWORD            cCertReference;
  DWORD            *rgdwCertReference;
  DWORD            cAttribute;
  PCRYPT_ATTRIBUTE rgAttribute;
} CMC_ADD_ATTRIBUTES_INFO, *PCMC_ADD_ATTRIBUTES_INFO;
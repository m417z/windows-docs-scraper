typedef struct _CMC_ADD_EXTENSIONS_INFO {
  DWORD           dwCmcDataReference;
  DWORD           cCertReference;
  DWORD           *rgdwCertReference;
  DWORD           cExtension;
  PCERT_EXTENSION rgExtension;
} CMC_ADD_EXTENSIONS_INFO, *PCMC_ADD_EXTENSIONS_INFO;
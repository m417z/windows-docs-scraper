typedef union {
  struct {
    ULONG NUMDU : 16;
    ULONG LogSpecificIdentifier : 16;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CDW11_GET_LOG_PAGE, *PNVME_CDW11_GET_LOG_PAGE;
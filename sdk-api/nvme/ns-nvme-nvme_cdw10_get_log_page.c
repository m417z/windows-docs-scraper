typedef union {
  struct {
    ULONG LID : 8;
    ULONG Reserved0 : 8;
    ULONG NUMD : 12;
    ULONG Reserved1 : 4;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CDW10_GET_LOG_PAGE, *PNVME_CDW10_GET_LOG_PAGE;
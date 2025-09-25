typedef union {
  struct {
    ULONG LID : 8;
    ULONG LSP : 4;
    ULONG Reserved0 : 3;
    ULONG RAE : 1;
    ULONG NUMDL : 16;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CDW10_GET_LOG_PAGE_V13, *PNVME_CDW10_GET_LOG_PAGE_V13;
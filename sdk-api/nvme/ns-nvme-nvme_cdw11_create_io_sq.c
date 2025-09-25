typedef union {
  struct {
    ULONG PC : 1;
    ULONG QPRIO : 2;
    ULONG Reserved0 : 13;
    ULONG CQID : 16;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CDW11_CREATE_IO_SQ, *PNVME_CDW11_CREATE_IO_SQ;
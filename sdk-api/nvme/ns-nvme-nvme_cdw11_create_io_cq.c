typedef union {
  struct {
    ULONG PC : 1;
    ULONG IEN : 1;
    ULONG Reserved0 : 14;
    ULONG IV : 16;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CDW11_CREATE_IO_CQ, *PNVME_CDW11_CREATE_IO_CQ;
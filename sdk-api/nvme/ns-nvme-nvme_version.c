typedef union {
  struct {
    ULONG TER : 8;
    ULONG MNR : 8;
    ULONG MJR : 16;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_VERSION, *PNVME_VERSION;
typedef union {
  struct {
    ULONG NLB : 16;
    ULONG Reserved0 : 4;
    ULONG DTYPE : 4;
    ULONG Reserved1 : 2;
    ULONG PRINFO : 4;
    ULONG FUA : 1;
    ULONG LR : 1;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CDW12_READ_WRITE, *PNVME_CDW12_READ_WRITE;
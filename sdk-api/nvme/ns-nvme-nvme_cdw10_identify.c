typedef union {
  struct {
    ULONG CNS : 8;
    ULONG Reserved : 8;
    ULONG CNTID : 16;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CDW10_IDENTIFY, *PNVME_CDW10_IDENTIFY;
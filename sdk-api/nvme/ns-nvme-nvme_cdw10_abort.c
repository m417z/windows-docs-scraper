typedef union {
  struct {
    ULONG SQID : 8;
    ULONG CID : 16;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CDW10_ABORT, *PNVME_CDW10_ABORT;
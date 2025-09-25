typedef union {
  struct {
    ULONGLONG Reserved0 : 2;
    ULONGLONG PBAO : 62;
  } DUMMYSTRUCTNAME;
  ULONGLONG AsUlonglong;
} NVME_PRP_ENTRY, *PNVME_PRP_ENTRY;
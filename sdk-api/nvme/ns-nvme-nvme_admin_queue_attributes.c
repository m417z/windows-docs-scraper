typedef union {
  struct {
    ULONG ASQS : 12;
    ULONG Reserved0 : 4;
    ULONG ACQS : 12;
    ULONG Reserved1 : 4;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_ADMIN_QUEUE_ATTRIBUTES, *PNVME_ADMIN_QUEUE_ATTRIBUTES;
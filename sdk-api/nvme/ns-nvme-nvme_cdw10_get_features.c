typedef union {
  struct {
    ULONG FID : 8;
    ULONG SEL : 3;
    ULONG Reserved0 : 21;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CDW10_GET_FEATURES, *PNVME_CDW10_GET_FEATURES;
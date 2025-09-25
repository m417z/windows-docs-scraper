typedef union {
  struct {
    ULONG FID : 8;
    ULONG Reserved0 : 23;
    ULONG SV : 1;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CDW10_SET_FEATURES, *PNVME_CDW10_SET_FEATURES;
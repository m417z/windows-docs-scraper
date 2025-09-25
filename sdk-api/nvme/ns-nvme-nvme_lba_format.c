typedef union {
  struct {
    USHORT MS;
    UCHAR  LBADS;
    UCHAR  RP : 2;
    UCHAR  Reserved0 : 6;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_LBA_FORMAT, *PNVME_LBA_FORMAT;
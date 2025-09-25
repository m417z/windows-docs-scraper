typedef union {
  struct {
    struct {
      UCHAR AccessFrequency : 4;
      UCHAR AccessLatency : 2;
      UCHAR SequentialRequest : 1;
      UCHAR Incompressible : 1;
    } DSM;
    UCHAR  Reserved;
    USHORT DSPEC;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CDW13_READ_WRITE, *PNVME_CDW13_READ_WRITE;
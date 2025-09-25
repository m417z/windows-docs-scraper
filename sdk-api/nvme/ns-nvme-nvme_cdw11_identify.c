typedef union {
  struct {
    USHORT NVMSETID;
    USHORT Reserved;
  } DUMMYSTRUCTNAME;
  struct {
    ULONG CNSID : 16;
    ULONG Reserved2 : 8;
    ULONG CSI : 8;
  } DUMMYSTRUCTNAME2;
  ULONG  AsUlong;
} NVME_CDW11_IDENTIFY, *PNVME_CDW11_IDENTIFY;
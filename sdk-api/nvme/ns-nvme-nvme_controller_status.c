typedef union {
  struct {
    ULONG RDY : 1;
    ULONG CFS : 1;
    ULONG SHST : 2;
    ULONG NSSRO : 1;
    ULONG PP : 1;
    ULONG Reserved0 : 26;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CONTROLLER_STATUS, *PNVME_CONTROLLER_STATUS;
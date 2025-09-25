typedef union {
  struct {
    USHORT P : 1;
    USHORT SC : 8;
    USHORT SCT : 3;
    USHORT Reserved : 2;
    USHORT M : 1;
    USHORT DNR : 1;
  } DUMMYSTRUCTNAME;
  USHORT AsUshort;
} NVME_COMMAND_STATUS, *PNVME_COMMAND_STATUS;
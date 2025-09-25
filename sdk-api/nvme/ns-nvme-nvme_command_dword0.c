typedef union {
  struct {
    ULONG OPC : 8;
    ULONG FUSE : 2;
    ULONG Reserved0 : 5;
    ULONG PSDT : 1;
    ULONG CID : 16;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_COMMAND_DWORD0, *PNVME_COMMAND_DWORD0;
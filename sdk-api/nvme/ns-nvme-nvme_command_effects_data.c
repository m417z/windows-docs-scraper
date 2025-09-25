typedef union {
  struct {
    ULONG CSUPP : 1;
    ULONG LBCC : 1;
    ULONG NCC : 1;
    ULONG NIC : 1;
    ULONG CCC : 1;
    ULONG Reserved0 : 11;
    ULONG CSE : 3;
    ULONG Reserved1 : 13;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_COMMAND_EFFECTS_DATA, *PNVME_COMMAND_EFFECTS_DATA;
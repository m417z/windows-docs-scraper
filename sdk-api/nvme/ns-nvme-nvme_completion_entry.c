typedef struct {
  ULONG DW0;
  ULONG DW1;
  union {
    struct {
      USHORT SQHD;
      USHORT SQID;
    } DUMMYSTRUCTNAME;
    ULONG AsUlong;
  } DW2;
  union {
    struct {
      USHORT              CID;
      NVME_COMMAND_STATUS Status;
    } DUMMYSTRUCTNAME;
    ULONG AsUlong;
  } DW3;
} NVME_COMPLETION_ENTRY, *PNVME_COMPLETION_ENTRY;
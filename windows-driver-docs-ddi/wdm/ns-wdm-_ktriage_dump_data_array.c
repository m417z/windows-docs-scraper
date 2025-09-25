typedef struct _KTRIAGE_DUMP_DATA_ARRAY {
  LIST_ENTRY     List;
  ULONG          NumBlocksUsed;
  ULONG          NumBlocksTotal;
  ULONG          DataSize;
  ULONG          MaxDataSize;
  ULONG          ComponentNameBufferLength;
  PUCHAR         ComponentName;
  KADDRESS_RANGE Blocks[ANYSIZE_ARRAY];
} KTRIAGE_DUMP_DATA_ARRAY, *PKTRIAGE_DUMP_DATA_ARRAY;
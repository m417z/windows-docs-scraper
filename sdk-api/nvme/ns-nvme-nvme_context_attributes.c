typedef union {
  struct {
    ULONG AccessFrequency : 4;
    ULONG AccessLatency : 2;
    ULONG Reserved0 : 2;
    ULONG SequentialReadRange : 1;
    ULONG SequentialWriteRange : 1;
    ULONG WritePrepare : 1;
    ULONG Reserved1 : 13;
    ULONG CommandAccessSize : 8;
  } DUMMYSTRUCTNAME;
  ULONG  AsUlong;
} NVME_CONTEXT_ATTRIBUTES, *PNVME_CONTEXT_ATTRIBUTES;
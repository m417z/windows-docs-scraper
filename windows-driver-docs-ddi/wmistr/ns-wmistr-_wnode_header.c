typedef struct _WNODE_HEADER {
  ULONG BufferSize;
  ULONG ProviderId;
  union {
    ULONG64 HistoricalContext;
    struct {
      ULONG Version;
      ULONG Linkage;
    } DUMMYSTRUCTNAME;
  } DUMMYUNIONNAME;
  union {
    ULONG         CountLost;
    HANDLE        KernelHandle;
    LARGE_INTEGER TimeStamp;
  } DUMMYUNIONNAME2;
  GUID  Guid;
  ULONG ClientContext;
  ULONG Flags;
} WNODE_HEADER, *PWNODE_HEADER;
typedef struct _EVENT_HEADER {
  USHORT           Size;
  USHORT           HeaderType;
  USHORT           Flags;
  USHORT           EventProperty;
  ULONG            ThreadId;
  ULONG            ProcessId;
  LARGE_INTEGER    TimeStamp;
  GUID             ProviderId;
  EVENT_DESCRIPTOR EventDescriptor;
  union {
    struct {
      ULONG KernelTime;
      ULONG UserTime;
    } DUMMYSTRUCTNAME;
    ULONG64 ProcessorTime;
  } DUMMYUNIONNAME;
  GUID             ActivityId;
} EVENT_HEADER, *PEVENT_HEADER;
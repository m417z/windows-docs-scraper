typedef struct _EVENT_TRACE_PROPERTIES_V2 {
  WNODE_HEADER             Wnode;
  ULONG                    BufferSize;
  ULONG                    MinimumBuffers;
  ULONG                    MaximumBuffers;
  ULONG                    MaximumFileSize;
  ULONG                    LogFileMode;
  ULONG                    FlushTimer;
  ULONG                    EnableFlags;
  union {
    LONG AgeLimit;
    LONG FlushThreshold;
  } DUMMYUNIONNAME;
  ULONG                    NumberOfBuffers;
  ULONG                    FreeBuffers;
  ULONG                    EventsLost;
  ULONG                    BuffersWritten;
  ULONG                    LogBuffersLost;
  ULONG                    RealTimeBuffersLost;
  HANDLE                   LoggerThreadId;
  ULONG                    LogFileNameOffset;
  ULONG                    LoggerNameOffset;
  union {
    struct {
      ULONG VersionNumber : 8;
    } DUMMYSTRUCTNAME;
    ULONG V2Control;
  } DUMMYUNIONNAME2;
  ULONG                    FilterDescCount;
  PEVENT_FILTER_DESCRIPTOR FilterDesc;
  union {
    struct {
      ULONG Wow : 1;
      ULONG QpcDeltaTracking : 1;
      ULONG LargeMdlPages : 1;
      ULONG ExcludeKernelStack : 1;
    } DUMMYSTRUCTNAME;
    ULONG64 V2Options;
  } DUMMYUNIONNAME3;
} EVENT_TRACE_PROPERTIES_V2, *PEVENT_TRACE_PROPERTIES_V2;
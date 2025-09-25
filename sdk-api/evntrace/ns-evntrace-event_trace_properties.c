typedef struct _EVENT_TRACE_PROPERTIES {
  WNODE_HEADER Wnode;
  ULONG        BufferSize;
  ULONG        MinimumBuffers;
  ULONG        MaximumBuffers;
  ULONG        MaximumFileSize;
  ULONG        LogFileMode;
  ULONG        FlushTimer;
  ULONG        EnableFlags;
  union {
    LONG AgeLimit;
    LONG FlushThreshold;
  } DUMMYUNIONNAME;
  ULONG        NumberOfBuffers;
  ULONG        FreeBuffers;
  ULONG        EventsLost;
  ULONG        BuffersWritten;
  ULONG        LogBuffersLost;
  ULONG        RealTimeBuffersLost;
  HANDLE       LoggerThreadId;
  ULONG        LogFileNameOffset;
  ULONG        LoggerNameOffset;
} EVENT_TRACE_PROPERTIES, *PEVENT_TRACE_PROPERTIES;
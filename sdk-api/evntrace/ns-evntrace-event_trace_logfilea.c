typedef struct _EVENT_TRACE_LOGFILEA {
  LPSTR                         LogFileName;
  LPSTR                         LoggerName;
  LONGLONG                      CurrentTime;
  ULONG                         BuffersRead;
  union {
    ULONG LogFileMode;
    ULONG ProcessTraceMode;
  } DUMMYUNIONNAME;
  EVENT_TRACE                   CurrentEvent;
  TRACE_LOGFILE_HEADER          LogfileHeader;
  PEVENT_TRACE_BUFFER_CALLBACKA BufferCallback;
  ULONG                         BufferSize;
  ULONG                         Filled;
  ULONG                         EventsLost;
  union {
    PEVENT_CALLBACK        EventCallback;
    PEVENT_RECORD_CALLBACK EventRecordCallback;
  } DUMMYUNIONNAME2;
  ULONG                         IsKernelTrace;
  PVOID                         Context;
} EVENT_TRACE_LOGFILEA, *PEVENT_TRACE_LOGFILEA;
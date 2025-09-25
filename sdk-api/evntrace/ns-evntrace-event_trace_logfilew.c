typedef struct _EVENT_TRACE_LOGFILEW {
  LPWSTR                        LogFileName;
  LPWSTR                        LoggerName;
  LONGLONG                      CurrentTime;
  ULONG                         BuffersRead;
  union {
    ULONG LogFileMode;
    ULONG ProcessTraceMode;
  } DUMMYUNIONNAME;
  EVENT_TRACE                   CurrentEvent;
  TRACE_LOGFILE_HEADER          LogfileHeader;
  PEVENT_TRACE_BUFFER_CALLBACKW BufferCallback;
  ULONG                         BufferSize;
  ULONG                         Filled;
  ULONG                         EventsLost;
  union {
    PEVENT_CALLBACK        EventCallback;
    PEVENT_RECORD_CALLBACK EventRecordCallback;
  } DUMMYUNIONNAME2;
  ULONG                         IsKernelTrace;
  PVOID                         Context;
} EVENT_TRACE_LOGFILEW, *PEVENT_TRACE_LOGFILEW;
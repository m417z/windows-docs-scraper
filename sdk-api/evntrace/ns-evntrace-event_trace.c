typedef struct _EVENT_TRACE {
  EVENT_TRACE_HEADER Header;
  ULONG              InstanceId;
  ULONG              ParentInstanceId;
  GUID               ParentGuid;
  PVOID              MofData;
  ULONG              MofLength;
  union {
    ULONG              ClientContext;
    ETW_BUFFER_CONTEXT BufferContext;
  } DUMMYUNIONNAME;
} EVENT_TRACE, *PEVENT_TRACE;
typedef struct _DEBUG_EVENT_CONTEXT {
  ULONG Size;
  ULONG ProcessEngineId;
  ULONG ThreadEngineId;
  ULONG FrameEngineId;
} DEBUG_EVENT_CONTEXT, *PDEBUG_EVENT_CONTEXT;
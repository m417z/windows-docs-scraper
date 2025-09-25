typedef struct _FSRTL_PER_STREAM_CONTEXT {
  LIST_ENTRY     Links;
  PVOID          OwnerId;
  PVOID          InstanceId;
  PFREE_FUNCTION FreeCallback;
} FSRTL_PER_STREAM_CONTEXT, *PFSRTL_PER_STREAM_CONTEXT;
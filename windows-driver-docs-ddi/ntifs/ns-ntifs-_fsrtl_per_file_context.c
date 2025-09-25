typedef struct _FSRTL_PER_FILE_CONTEXT {
  LIST_ENTRY     Links;
  PVOID          OwnerId;
  PVOID          InstanceId;
  PFREE_FUNCTION FreeCallback;
} FSRTL_PER_FILE_CONTEXT, *PFSRTL_PER_FILE_CONTEXT;
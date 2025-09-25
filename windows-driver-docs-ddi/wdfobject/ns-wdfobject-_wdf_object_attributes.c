typedef struct _WDF_OBJECT_ATTRIBUTES {
  ULONG                          Size;
  PFN_WDF_OBJECT_CONTEXT_CLEANUP EvtCleanupCallback;
  PFN_WDF_OBJECT_CONTEXT_DESTROY EvtDestroyCallback;
  WDF_EXECUTION_LEVEL            ExecutionLevel;
  WDF_SYNCHRONIZATION_SCOPE      SynchronizationScope;
  WDFOBJECT                      ParentObject;
  size_t                         ContextSizeOverride;
  PCWDF_OBJECT_CONTEXT_TYPE_INFO ContextTypeInfo;
} WDF_OBJECT_ATTRIBUTES, *PWDF_OBJECT_ATTRIBUTES;
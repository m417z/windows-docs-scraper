typedef struct _WDF_OBJECT_CONTEXT_TYPE_INFO {
  ULONG                          Size;
  LPCSTR                         ContextName;
  size_t                         ContextSize;
  PCWDF_OBJECT_CONTEXT_TYPE_INFO UniqueType;
  PFN_GET_UNIQUE_CONTEXT_TYPE    EvtDriverGetUniqueContextType;
} WDF_OBJECT_CONTEXT_TYPE_INFO, *PWDF_OBJECT_CONTEXT_TYPE_INFO;
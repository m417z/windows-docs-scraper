typedef struct _FLT_RELATED_CONTEXTS {
  PFLT_CONTEXT VolumeContext;
  PFLT_CONTEXT InstanceContext;
  PFLT_CONTEXT FileContext;
  PFLT_CONTEXT StreamContext;
  PFLT_CONTEXT StreamHandleContext;
  PFLT_CONTEXT TransactionContext;
} FLT_RELATED_CONTEXTS, *PFLT_RELATED_CONTEXTS;
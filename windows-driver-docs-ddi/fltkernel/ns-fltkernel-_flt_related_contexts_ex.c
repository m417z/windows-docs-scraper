typedef struct _FLT_RELATED_CONTEXTS_EX {
  PFLT_CONTEXT VolumeContext;
  PFLT_CONTEXT InstanceContext;
  PFLT_CONTEXT FileContext;
  PFLT_CONTEXT StreamContext;
  PFLT_CONTEXT StreamHandleContext;
  PFLT_CONTEXT TransactionContext;
  PFLT_CONTEXT SectionContext;
} FLT_RELATED_CONTEXTS_EX, *PFLT_RELATED_CONTEXTS_EX;
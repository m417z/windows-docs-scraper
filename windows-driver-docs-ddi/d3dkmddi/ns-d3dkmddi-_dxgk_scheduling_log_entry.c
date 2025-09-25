typedef struct _DXGK_SCHEDULING_LOG_ENTRY {
  UINT64 GpuTimeStamp;
  UINT   OperationType : 32;
  UINT   ReservedOperationTypeBits : 32;
  union {
    DXGK_SCHEDULING_LOG_CONTEXT_STATE_CHANGE ContextStateChange;
    UINT64                                   ReservedOperationData[2];
  };
} DXGK_SCHEDULING_LOG_ENTRY;
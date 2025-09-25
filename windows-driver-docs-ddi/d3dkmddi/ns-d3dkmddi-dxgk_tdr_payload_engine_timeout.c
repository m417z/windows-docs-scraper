typedef struct _DXGK_TDR_PAYLOAD_ENGINE_TIMEOUT {
  UINT      NodeOrdinal;
  UINT      EngineOrdinal;
  ULONGLONG LastHwCompletedFenceId;
  ULONGLONG LastHwSubmittedFenceId;
  ULONG     NumberOfPendingSuspendRequests;
  ULONG     NumberOfReadyInteractiveHwQueues;
  HANDLE    hContext;
} DXGK_TDR_PAYLOAD_ENGINE_TIMEOUT;
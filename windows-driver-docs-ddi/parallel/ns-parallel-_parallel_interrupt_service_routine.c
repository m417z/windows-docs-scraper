typedef struct _PARALLEL_INTERRUPT_SERVICE_ROUTINE {
  PKSERVICE_ROUTINE          InterruptServiceRoutine;
  PVOID                      InterruptServiceContext;
  PPARALLEL_DEFERRED_ROUTINE DeferredPortCheckRoutine;
  PVOID                      DeferredPortCheckContext;
} PARALLEL_INTERRUPT_SERVICE_ROUTINE, *PPARALLEL_INTERRUPT_SERVICE_ROUTINE;
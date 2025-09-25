typedef struct _DRIVER_PROXY_HOTSWAP_WORKER_ROUTINE_START_CONTEXT {
  PDRIVER_PROXY_HOTSWAP_WORKER_ROUTINE WorkerRoutine;
  PVOID                                Context;
  WAIT_TYPE                            WaitType;
  KWAIT_REASON                         WaitReason;
  KPROCESSOR_MODE                      WaitMode;
  BOOLEAN                              Altertable;
  BOOLEAN                              HasTimeout;
  LARGE_INTEGER                        Timeout;
  ULONG                                EventCount;
  PKEVENT                              Events[ANYSIZE_ARRAY];
} DRIVER_PROXY_HOTSWAP_WORKER_ROUTINE_START_CONTEXT, *PDRIVER_PROXY_HOTSWAP_WORKER_ROUTINE_START_CONTEXT;
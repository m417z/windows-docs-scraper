typedef struct _ACX_DEVICEINIT_CONFIG {
  ULONG                     Size;
  ULONG                     Flags;
  WDF_SYNCHRONIZATION_SCOPE SynchronizationScope;
  WDF_EXECUTION_LEVEL       ExecutionLevel;
  PVOID                     Context[ACX_DEVICEINIT_CONFIG_CONTEXT_SIZE];
} ACX_DEVICEINIT_CONFIG, *PACX_DEVICEINIT_CONFIG;
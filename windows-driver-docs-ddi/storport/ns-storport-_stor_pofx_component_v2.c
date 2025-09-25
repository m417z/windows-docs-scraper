typedef struct _STOR_POFX_COMPONENT_V2 {
  ULONG                          Version;
  ULONG                          Size;
  ULONG                          FStateCount;
  ULONG                          DeepestWakeableFState;
  GUID                           Id;
  ULONG                          DeepestAdapterPowerRequiredFState;
  ULONG                          DeepestCrashDumpReadyFState;
  STOR_POFX_COMPONENT_IDLE_STATE FStates[ANYSIZE_ARRAY];
} STOR_POFX_COMPONENT_V2, *PSTOR_POFX_COMPONENT_V2;
typedef struct _STOR_POFX_COMPONENT {
  ULONG                          Version;
  ULONG                          Size;
  ULONG                          FStateCount;
  ULONG                          DeepestWakeableFState;
  GUID                           Id;
  STOR_POFX_COMPONENT_IDLE_STATE FStates[ANYSIZE_ARRAY];
} STOR_POFX_COMPONENT, *PSTOR_POFX_COMPONENT;
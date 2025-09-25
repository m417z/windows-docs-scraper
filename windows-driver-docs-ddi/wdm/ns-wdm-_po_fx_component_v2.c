typedef struct _PO_FX_COMPONENT_V2 {
  GUID                        Id;
  ULONGLONG                   Flags;
  ULONG                       DeepestWakeableIdleState;
  ULONG                       IdleStateCount;
  PPO_FX_COMPONENT_IDLE_STATE IdleStates;
  ULONG                       ProviderCount;
  PULONG                      Providers;
} PO_FX_COMPONENT_V2, *PPO_FX_COMPONENT_V2;
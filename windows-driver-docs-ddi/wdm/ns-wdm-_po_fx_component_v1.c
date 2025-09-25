typedef struct _PO_FX_COMPONENT_V1 {
  GUID                        Id;
  ULONG                       IdleStateCount;
  ULONG                       DeepestWakeableIdleState;
  PPO_FX_COMPONENT_IDLE_STATE IdleStates;
} PO_FX_COMPONENT_V1, *PPO_FX_COMPONENT_V1;
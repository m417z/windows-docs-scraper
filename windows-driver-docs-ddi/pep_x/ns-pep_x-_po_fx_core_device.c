typedef struct _PO_FX_CORE_DEVICE {
  ULONG                                         Version;
  ULONG                                         ComponentCount;
  PPO_FX_COMPONENT_ACTIVE_CONDITION_CALLBACK    ComponentActiveConditionCallback;
  PPO_FX_COMPONENT_IDLE_CONDITION_CALLBACK      ComponentIdleConditionCallback;
  PPO_FX_COMPONENT_CRITICAL_TRANSITION_CALLBACK ComponentCriticalTransitionCallback;
  PPO_FX_COMPONENT_IDLE_STATE_CALLBACK          ComponentIdleStateCallback;
  PVOID                                         DeviceContext;
  PO_FX_COMPONENT                               Components[ANYSIZE_ARRAY];
} PO_FX_CORE_DEVICE, *PPO_FX_CORE_DEVICE;
typedef struct _PO_FX_DEVICE_V1 {
  ULONG                                      Version;
  ULONG                                      ComponentCount;
  PPO_FX_COMPONENT_ACTIVE_CONDITION_CALLBACK ComponentActiveConditionCallback;
  PPO_FX_COMPONENT_IDLE_CONDITION_CALLBACK   ComponentIdleConditionCallback;
  PPO_FX_COMPONENT_IDLE_STATE_CALLBACK       ComponentIdleStateCallback;
  PPO_FX_DEVICE_POWER_REQUIRED_CALLBACK      DevicePowerRequiredCallback;
  PPO_FX_DEVICE_POWER_NOT_REQUIRED_CALLBACK  DevicePowerNotRequiredCallback;
  PPO_FX_POWER_CONTROL_CALLBACK              PowerControlCallback;
  PVOID                                      DeviceContext;
  PO_FX_COMPONENT_V1                         Components[ANYSIZE_ARRAY];
} PO_FX_DEVICE_V1, *PPO_FX_DEVICE_V1;
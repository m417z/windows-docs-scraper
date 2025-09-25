typedef struct _PO_FX_DEVICE_V3 {
  ULONG                                      Version;
  ULONGLONG                                  Flags;
  PPO_FX_COMPONENT_ACTIVE_CONDITION_CALLBACK ComponentActiveConditionCallback;
  PPO_FX_COMPONENT_IDLE_CONDITION_CALLBACK   ComponentIdleConditionCallback;
  PPO_FX_COMPONENT_IDLE_STATE_CALLBACK       ComponentIdleStateCallback;
  PPO_FX_DEVICE_POWER_REQUIRED_CALLBACK      DevicePowerRequiredCallback;
  PPO_FX_DEVICE_POWER_NOT_REQUIRED_CALLBACK  DevicePowerNotRequiredCallback;
  PPO_FX_POWER_CONTROL_CALLBACK              PowerControlCallback;
  PPO_FX_DIRECTED_POWER_UP_CALLBACK          DirectedPowerUpCallback;
  PPO_FX_DIRECTED_POWER_DOWN_CALLBACK        DirectedPowerDownCallback;
  ULONG                                      DirectedFxTimeoutInSeconds;
  PVOID                                      DeviceContext;
  ULONG                                      ComponentCount;
  PO_FX_COMPONENT_V2                         Components[ANYSIZE_ARRAY];
} PO_FX_DEVICE_V3, *PPO_FX_DEVICE_V3;
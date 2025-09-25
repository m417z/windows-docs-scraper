typedef struct _WDF_POWER_FRAMEWORK_SETTINGS {
  ULONG                                         Size;
  PFN_WDFDEVICE_WDM_POST_PO_FX_REGISTER_DEVICE  EvtDeviceWdmPostPoFxRegisterDevice;
  PFN_WDFDEVICE_WDM_PRE_PO_FX_UNREGISTER_DEVICE EvtDeviceWdmPrePoFxUnregisterDevice;
  PPO_FX_COMPONENT                              Component;
  PPO_FX_COMPONENT_ACTIVE_CONDITION_CALLBACK    ComponentActiveConditionCallback;
  PPO_FX_COMPONENT_IDLE_CONDITION_CALLBACK      ComponentIdleConditionCallback;
  PPO_FX_COMPONENT_IDLE_STATE_CALLBACK          ComponentIdleStateCallback;
  PPO_FX_POWER_CONTROL_CALLBACK                 PowerControlCallback;
  PVOID                                         PoFxDeviceContext;
  ULONGLONG                                     PoFxDeviceFlags;
  WDF_TRI_STATE                                 DirectedPoFxEnabled;
} WDF_POWER_FRAMEWORK_SETTINGS, *PWDF_POWER_FRAMEWORK_SETTINGS;
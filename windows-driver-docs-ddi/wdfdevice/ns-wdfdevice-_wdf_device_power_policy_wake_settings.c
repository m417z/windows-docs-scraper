typedef struct _WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS {
  ULONG                                 Size;
  DEVICE_POWER_STATE                    DxState;
  WDF_POWER_POLICY_SX_WAKE_USER_CONTROL UserControlOfWakeSettings;
  WDF_TRI_STATE                         Enabled;
  BOOLEAN                               ArmForWakeIfChildrenAreArmedForWake;
  BOOLEAN                               IndicateChildWakeOnParentWake;
} WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS, *PWDF_DEVICE_POWER_POLICY_WAKE_SETTINGS;
typedef struct _WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS {
  ULONG                                 Size;
  WDF_POWER_POLICY_S0_IDLE_CAPABILITIES IdleCaps;
  DEVICE_POWER_STATE                    DxState;
  ULONG                                 IdleTimeout;
  WDF_POWER_POLICY_S0_IDLE_USER_CONTROL UserControlOfIdleSettings;
  WDF_TRI_STATE                         Enabled;
  WDF_TRI_STATE                         PowerUpIdleDeviceOnSystemWake;
  WDF_TRI_STATE                         ExcludeD3Cold;
} WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS, *PWUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS;
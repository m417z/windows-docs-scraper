typedef struct _WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS {
  ULONG                                 Size;
  WDF_POWER_POLICY_S0_IDLE_CAPABILITIES IdleCaps;
  DEVICE_POWER_STATE                    DxState;
  ULONG                                 IdleTimeout;
  WDF_POWER_POLICY_S0_IDLE_USER_CONTROL UserControlOfIdleSettings;
  WDF_TRI_STATE                         Enabled;
  WDF_TRI_STATE                         PowerUpIdleDeviceOnSystemWake;
  WDF_POWER_POLICY_IDLE_TIMEOUT_TYPE    IdleTimeoutType;
  WDF_TRI_STATE                         ExcludeD3Cold;
} WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS, *PWDF_DEVICE_POWER_POLICY_IDLE_SETTINGS;
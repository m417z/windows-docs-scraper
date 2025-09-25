HRESULT AssignS0IdleSettings(
  [in] WDF_POWER_POLICY_S0_IDLE_CAPABILITIES IdleCaps,
  [in] DEVICE_POWER_STATE                    DxState,
  [in] ULONG                                 IdleTimeout,
  [in] WDF_POWER_POLICY_S0_IDLE_USER_CONTROL UserControlOfIdleSettings,
  [in] WDF_TRI_STATE                         Enabled
);
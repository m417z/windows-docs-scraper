typedef enum _WDF_POWER_POLICY_S0_IDLE_CAPABILITIES {
  IdleCapsInvalid = 0,
  IdleCannotWakeFromS0,
  IdleCanWakeFromS0,
  IdleUsbSelectiveSuspend
} WDF_POWER_POLICY_S0_IDLE_CAPABILITIES;
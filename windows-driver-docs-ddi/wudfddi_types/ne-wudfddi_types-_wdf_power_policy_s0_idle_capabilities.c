typedef enum _WDF_POWER_POLICY_S0_IDLE_CAPABILITIES {
  IdleCapsInvalid,
  IdleCannotWakeFromS0,
  IdleCanWakeFromS0,
  IdleUsbSelectiveSuspend
} WDF_POWER_POLICY_S0_IDLE_CAPABILITIES;
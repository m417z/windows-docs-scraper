typedef enum _WDF_POWER_POLICY_IDLE_TIMEOUT_TYPE {
  DriverManagedIdleTimeout = 0,
  SystemManagedIdleTimeout = 1,
  SystemManagedIdleTimeoutWithHint = 2
} WDF_POWER_POLICY_IDLE_TIMEOUT_TYPE, *PWDF_POWER_POLICY_IDLE_TIMEOUT_TYPE;
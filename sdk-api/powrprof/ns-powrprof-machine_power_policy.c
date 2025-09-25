typedef struct _MACHINE_POWER_POLICY {
  ULONG               Revision;
  SYSTEM_POWER_STATE  MinSleepAc;
  SYSTEM_POWER_STATE  MinSleepDc;
  SYSTEM_POWER_STATE  ReducedLatencySleepAc;
  SYSTEM_POWER_STATE  ReducedLatencySleepDc;
  ULONG               DozeTimeoutAc;
  ULONG               DozeTimeoutDc;
  ULONG               DozeS4TimeoutAc;
  ULONG               DozeS4TimeoutDc;
  UCHAR               MinThrottleAc;
  UCHAR               MinThrottleDc;
  UCHAR               pad1[2];
  POWER_ACTION_POLICY OverThrottledAc;
  POWER_ACTION_POLICY OverThrottledDc;
} MACHINE_POWER_POLICY, *PMACHINE_POWER_POLICY;
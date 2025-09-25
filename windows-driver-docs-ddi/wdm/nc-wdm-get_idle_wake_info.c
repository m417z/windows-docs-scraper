GET_IDLE_WAKE_INFO GetIdleWakeInfo;

NTSTATUS GetIdleWakeInfo(
  [in, optional] PVOID Context,
  [in]           SYSTEM_POWER_STATE SystemPowerState,
  [out]          PDEVICE_WAKE_DEPTH DeepestWakeableDstate
)
{...}
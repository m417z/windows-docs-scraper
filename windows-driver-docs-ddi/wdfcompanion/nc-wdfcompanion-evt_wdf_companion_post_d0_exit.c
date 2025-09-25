EVT_WDF_COMPANION_POST_D0_EXIT EvtWdfCompanionPostD0Exit;

NTSTATUS EvtWdfCompanionPostD0Exit(
  [in] WDFCOMPANION Companion,
  [in] WDF_POWER_DEVICE_STATE TargetState
)
{...}
EVT_WDF_COMPANION_PRE_D0_ENTRY EvtWdfCompanionPreD0Entry;

NTSTATUS EvtWdfCompanionPreD0Entry(
  [in] WDFCOMPANION Companion,
  [in] WDF_POWER_DEVICE_STATE PreviousState
)
{...}
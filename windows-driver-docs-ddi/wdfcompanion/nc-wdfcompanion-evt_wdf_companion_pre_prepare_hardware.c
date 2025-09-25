EVT_WDF_COMPANION_PRE_PREPARE_HARDWARE EvtWdfCompanionPrePrepareHardware;

NTSTATUS EvtWdfCompanionPrePrepareHardware(
  [in] WDFCOMPANION Companion,
  [in] WDFCMRESLIST ResourcesRaw,
  [in] WDFCMRESLIST ResourcesTranslated
)
{...}
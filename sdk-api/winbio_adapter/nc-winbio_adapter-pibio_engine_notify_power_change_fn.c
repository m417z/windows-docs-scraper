PIBIO_ENGINE_NOTIFY_POWER_CHANGE_FN PibioEngineNotifyPowerChangeFn;

HRESULT PibioEngineNotifyPowerChangeFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      ULONG PowerEventType
)
{...}
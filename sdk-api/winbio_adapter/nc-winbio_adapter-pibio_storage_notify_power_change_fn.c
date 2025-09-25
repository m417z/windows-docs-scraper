PIBIO_STORAGE_NOTIFY_POWER_CHANGE_FN PibioStorageNotifyPowerChangeFn;

HRESULT PibioStorageNotifyPowerChangeFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      ULONG PowerEventType
)
{...}
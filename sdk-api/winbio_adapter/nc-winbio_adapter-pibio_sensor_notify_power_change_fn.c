PIBIO_SENSOR_NOTIFY_POWER_CHANGE_FN PibioSensorNotifyPowerChangeFn;

HRESULT PibioSensorNotifyPowerChangeFn(
  [in, out] PWINBIO_PIPELINE Pipeline,
  [in]      ULONG PowerEventType
)
{...}
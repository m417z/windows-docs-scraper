EVT_SENSOR_DRIVER_SET_DATA_INTERVAL EvtSensorDriverSetDataInterval;

NTSTATUS EvtSensorDriverSetDataInterval(
  [in] SENSOROBJECT Sensor,
  [in] ULONG DataRateMs
)
{...}
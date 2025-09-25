EVT_SENSOR_DRIVER_GET_DATA_INTERVAL EvtSensorDriverGetDataInterval;

NTSTATUS EvtSensorDriverGetDataInterval(
  [in]  SENSOROBJECT Sensor,
  [out] PULONG pDataRateMs
)
{...}
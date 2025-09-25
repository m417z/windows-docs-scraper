EVT_SENSOR_DRIVER_GET_PROPERTIES EvtSensorDriverGetProperties;

NTSTATUS EvtSensorDriverGetProperties(
  [in]                SENSOROBJECT Sensor,
  [in, out, optional] PSENSOR_COLLECTION_LIST pProperties,
  [out]               PULONG pSize
)
{...}
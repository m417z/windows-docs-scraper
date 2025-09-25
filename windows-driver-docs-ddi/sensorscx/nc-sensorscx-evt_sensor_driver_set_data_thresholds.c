EVT_SENSOR_DRIVER_SET_DATA_THRESHOLDS EvtSensorDriverSetDataThresholds;

NTSTATUS EvtSensorDriverSetDataThresholds(
  [in] SENSOROBJECT Sensor,
  [in] PSENSOR_COLLECTION_LIST pThresholds
)
{...}
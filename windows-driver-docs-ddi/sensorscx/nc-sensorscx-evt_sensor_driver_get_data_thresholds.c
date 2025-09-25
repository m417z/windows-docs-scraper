EVT_SENSOR_DRIVER_GET_DATA_THRESHOLDS EvtSensorDriverGetDataThresholds;

NTSTATUS EvtSensorDriverGetDataThresholds(
  [in]  SENSOROBJECT Sensor,
  [out] PSENSOR_COLLECTION_LIST pThresholds,
        PULONG pSize
)
{...}
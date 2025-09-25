EVT_SENSOR_DRIVER_SET_BATCH_LATENCY EvtSensorDriverSetBatchLatency;

NTSTATUS EvtSensorDriverSetBatchLatency(
  [in] SENSOROBJECT Sensor,
  [in] ULONG BatchLatencyMs
)
{...}
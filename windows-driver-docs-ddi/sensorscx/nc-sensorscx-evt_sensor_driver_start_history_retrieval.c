EVT_SENSOR_DRIVER_START_HISTORY_RETRIEVAL EvtSensorDriverStartHistoryRetrieval;

NTSTATUS EvtSensorDriverStartHistoryRetrieval(
  [in]      SENSOROBJECT Sensor,
  [in, out] PSENSOR_COLLECTION_LIST pHistory,
  [in]      ULONG HistorySizeInBytes
)
{...}
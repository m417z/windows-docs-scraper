EVT_SENSOR_DRIVER_GET_SUPPORTED_DATA_FIELDS EvtSensorDriverGetSupportedDataFields;

NTSTATUS EvtSensorDriverGetSupportedDataFields(
  [in]                SENSOROBJECT Sensor,
  [in, out, optional] PSENSOR_PROPERTY_LIST pDataFields,
  [out]               PULONG pSize
)
{...}
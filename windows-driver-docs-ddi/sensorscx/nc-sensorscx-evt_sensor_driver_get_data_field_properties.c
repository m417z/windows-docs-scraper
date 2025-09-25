EVT_SENSOR_DRIVER_GET_DATA_FIELD_PROPERTIES EvtSensorDriverGetDataFieldProperties;

NTSTATUS EvtSensorDriverGetDataFieldProperties(
  [in]                SENSOROBJECT Sensor,
  [in]                const PROPERTYKEY *pDataField,
  [in, out, optional] PSENSOR_COLLECTION_LIST pProperties,
  [out]               PULONG pSize
)
{...}
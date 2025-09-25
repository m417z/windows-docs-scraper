PFN_SENSORSCXSENSORINITIALIZE PfnSensorscxsensorinitialize;

NTSTATUS * PfnSensorscxsensorinitialize(
  PSENSORSCX_DRIVER_GLOBALS DriverGlobals,
  SENSOROBJECT Sensor,
  PSENSOR_CONFIG pSensorConfig
)
{...}
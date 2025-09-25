PFN_SENSORSCXSENSORCREATE PfnSensorscxsensorcreate;

NTSTATUS * PfnSensorscxsensorcreate(
  PSENSORSCX_DRIVER_GLOBALS DriverGlobals,
  WDFDEVICE FxDevice,
  PWDF_OBJECT_ATTRIBUTES pSensorAttributes,
  PSENSOROBJECT pSensor
)
{...}
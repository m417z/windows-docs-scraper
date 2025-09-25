PFN_SENSORSCXDEVICEINITIALIZE PfnSensorscxdeviceinitialize;

NTSTATUS * PfnSensorscxdeviceinitialize(
  PSENSORSCX_DRIVER_GLOBALS DriverGlobals,
  WDFDEVICE FxDevice,
  PSENSOR_CONTROLLER_CONFIG pSensorConfig
)
{...}
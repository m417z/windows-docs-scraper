PFN_SENSORSCXDEVICEINITCONFIG PfnSensorscxdeviceinitconfig;

NTSTATUS * PfnSensorscxdeviceinitconfig(
  PSENSORSCX_DRIVER_GLOBALS DriverGlobals,
  PWDFDEVICE_INIT pFxDeviceInit,
  PWDF_OBJECT_ATTRIBUTES pFdoAttributes,
  ULONG Flags
)
{...}
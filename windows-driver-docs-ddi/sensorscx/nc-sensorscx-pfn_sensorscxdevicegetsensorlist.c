PFN_SENSORSCXDEVICEGETSENSORLIST PfnSensorscxdevicegetsensorlist;

NTSTATUS * PfnSensorscxdevicegetsensorlist(
  PSENSORSCX_DRIVER_GLOBALS DriverGlobals,
  WDFDEVICE FxDevice,
  SENSOROBJECT *pSensorList,
  PULONG pListCount
)
{...}
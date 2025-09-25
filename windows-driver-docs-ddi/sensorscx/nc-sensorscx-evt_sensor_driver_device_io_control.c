EVT_SENSOR_DRIVER_DEVICE_IO_CONTROL EvtSensorDriverDeviceIoControl;

NTSTATUS EvtSensorDriverDeviceIoControl(
  SENSOROBJECT Sensor,
  WDFREQUEST Request,
  size_t OutputBufferLength,
  size_t InputBufferLength,
  ULONG IoControlCode
)
{...}
DRIVER_ADD_DEVICE DriverAddDevice;

NTSTATUS DriverAddDevice(
  [in] _DRIVER_OBJECT *DriverObject,
  [in] _DEVICE_OBJECT *PhysicalDeviceObject
)
{...}
DRIVER_CONTROL DriverControl;

IO_ALLOCATION_ACTION DriverControl(
  [in]      _DEVICE_OBJECT *DeviceObject,
  [in, out] _IRP *Irp,
  [in]      PVOID MapRegisterBase,
  [in]      PVOID Context
)
{...}
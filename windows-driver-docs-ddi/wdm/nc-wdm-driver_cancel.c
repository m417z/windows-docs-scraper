DRIVER_CANCEL DriverCancel;

VOID DriverCancel(
  [in, out] _DEVICE_OBJECT *DeviceObject,
  [in, out] _IRP *Irp
)
{...}
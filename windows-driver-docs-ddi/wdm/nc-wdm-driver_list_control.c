DRIVER_LIST_CONTROL DriverListControl;

VOID DriverListControl(
  [in] _DEVICE_OBJECT *DeviceObject,
  [in] _IRP *Irp,
  [in] PSCATTER_GATHER_LIST ScatterGather,
  [in] PVOID Context
)
{...}
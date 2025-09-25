IO_DPC_ROUTINE IoDpcRoutine;

VOID IoDpcRoutine(
  [in]           PKDPC Dpc,
  [in]           _DEVICE_OBJECT *DeviceObject,
  [in, out]      _IRP *Irp,
  [in, optional] PVOID Context
)
{...}
DRIVER_INITIALIZE DriverInitialize;

NTSTATUS DriverInitialize(
  [in] _DRIVER_OBJECT *DriverObject,
  [in] PUNICODE_STRING RegistryPath
)
{...}
NTSTATUS BATTERYCLASSAPI BatteryClassSystemControl(
  [in]      PVOID          ClassData,
  [in]      PVOID          WmiLibContext,
  [in]      PDEVICE_OBJECT DeviceObject,
  [in, out] PIRP           Irp,
  [out]     PVOID          Disposition
);
NTSTATUS WmiSystemControl(
  [in]      PWMILIB_CONTEXT         WmiLibInfo,
  [in]      PDEVICE_OBJECT          DeviceObject,
  [in, out] PIRP                    Irp,
  [out]     PSYSCTL_IRP_DISPOSITION IrpDisposition
);
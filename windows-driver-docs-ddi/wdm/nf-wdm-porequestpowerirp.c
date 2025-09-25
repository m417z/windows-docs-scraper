NTSTATUS PoRequestPowerIrp(
  [in]           PDEVICE_OBJECT          DeviceObject,
  [in]           UCHAR                   MinorFunction,
  [in]           POWER_STATE             PowerState,
  [in, optional] PREQUEST_POWER_COMPLETE CompletionFunction,
  [in, optional] __drv_aliasesMem PVOID  Context,
  [out]          PIRP                    *Irp
);
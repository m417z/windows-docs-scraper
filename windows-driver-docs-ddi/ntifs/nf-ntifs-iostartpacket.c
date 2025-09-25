VOID IoStartPacket(
  [in]           PDEVICE_OBJECT DeviceObject,
  [in]           PIRP           Irp,
  [in, optional] PULONG         Key,
  [in, optional] PDRIVER_CANCEL CancelFunction
);
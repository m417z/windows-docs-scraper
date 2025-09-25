PORTCLASSAPI NTSTATUS PcCompleteIrp(
  [in] PDEVICE_OBJECT pDeviceObject,
  [in] PIRP           pIrp,
  [in] NTSTATUS       ntStatus
);
WMI_SET_DATAITEM_CALLBACK WmiSetDataitemCallback;

NTSTATUS WmiSetDataitemCallback(
  [in] PDEVICE_OBJECT DeviceObject,
  [in] PIRP Irp,
  [in] ULONG GuidIndex,
  [in] ULONG InstanceIndex,
  [in] ULONG DataItemId,
  [in] ULONG BufferSize,
  [in] PUCHAR Buffer
)
{...}
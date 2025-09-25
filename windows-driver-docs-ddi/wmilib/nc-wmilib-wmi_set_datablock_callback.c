WMI_SET_DATABLOCK_CALLBACK WmiSetDatablockCallback;

NTSTATUS WmiSetDatablockCallback(
  [in] PDEVICE_OBJECT DeviceObject,
  [in] PIRP Irp,
  [in] ULONG GuidIndex,
  [in] ULONG InstanceIndex,
  [in] ULONG BufferSize,
  [in] PUCHAR Buffer
)
{...}
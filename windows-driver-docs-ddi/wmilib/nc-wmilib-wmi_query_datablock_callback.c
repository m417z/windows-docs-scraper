WMI_QUERY_DATABLOCK_CALLBACK WmiQueryDatablockCallback;

NTSTATUS WmiQueryDatablockCallback(
  [in]      PDEVICE_OBJECT DeviceObject,
  [in]      PIRP Irp,
  [in]      ULONG GuidIndex,
  [in]      ULONG InstanceIndex,
  [in]      ULONG InstanceCount,
  [in, out] PULONG InstanceLengthArray,
  [in]      ULONG BufferAvail,
  [out]     PUCHAR Buffer
)
{...}
PALLOCATE_ADAPTER_CHANNEL PallocateAdapterChannel;

NTSTATUS PallocateAdapterChannel(
  [in] PDMA_ADAPTER DmaAdapter,
  [in] PDEVICE_OBJECT DeviceObject,
  [in] ULONG NumberOfMapRegisters,
  [in] PDRIVER_CONTROL ExecutionRoutine,
  [in] PVOID Context
)
{...}
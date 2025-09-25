PALLOCATE_ADAPTER_CHANNEL_EX PallocateAdapterChannelEx;

NTSTATUS PallocateAdapterChannelEx(
  [in]            PDMA_ADAPTER DmaAdapter,
  [in]            PDEVICE_OBJECT DeviceObject,
  [in]            PVOID DmaTransferContext,
  [in]            ULONG NumberOfMapRegisters,
  [in]            ULONG Flags,
  [in, optional]  PDRIVER_CONTROL ExecutionRoutine,
  [in, optional]  PVOID ExecutionContext,
  [out, optional] PVOID *MapRegisterBase
)
{...}
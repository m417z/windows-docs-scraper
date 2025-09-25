PGET_SCATTER_GATHER_LIST_EX PgetScatterGatherListEx;

NTSTATUS PgetScatterGatherListEx(
  [in]            PDMA_ADAPTER DmaAdapter,
  [in]            PDEVICE_OBJECT DeviceObject,
  [in]            PVOID DmaTransferContext,
  [in]            PMDL Mdl,
  [in]            ULONGLONG Offset,
  [in]            ULONG Length,
  [in]            ULONG Flags,
  [in, optional]  PDRIVER_LIST_CONTROL ExecutionRoutine,
  [in, optional]  PVOID Context,
  [in]            BOOLEAN WriteToDevice,
  [in, optional]  PDMA_COMPLETION_ROUTINE DmaCompletionRoutine,
  [in, optional]  PVOID CompletionContext,
  [out, optional] PSCATTER_GATHER_LIST *ScatterGatherList
)
{...}
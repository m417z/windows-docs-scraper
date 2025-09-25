PBUILD_SCATTER_GATHER_LIST PbuildScatterGatherList;

NTSTATUS PbuildScatterGatherList(
  [in] PDMA_ADAPTER DmaAdapter,
  [in] PDEVICE_OBJECT DeviceObject,
  [in] PMDL Mdl,
  [in] PVOID CurrentVa,
  [in] ULONG Length,
  [in] PDRIVER_LIST_CONTROL ExecutionRoutine,
  [in] PVOID Context,
  [in] BOOLEAN WriteToDevice,
  [in] PVOID ScatterGatherBuffer,
  [in] ULONG ScatterGatherLength
)
{...}
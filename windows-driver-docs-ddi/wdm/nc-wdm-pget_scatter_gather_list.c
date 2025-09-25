PGET_SCATTER_GATHER_LIST PgetScatterGatherList;

NTSTATUS PgetScatterGatherList(
  [in] PDMA_ADAPTER DmaAdapter,
  [in] PDEVICE_OBJECT DeviceObject,
  [in] PMDL Mdl,
  [in] PVOID CurrentVa,
  [in] ULONG Length,
  [in] PDRIVER_LIST_CONTROL ExecutionRoutine,
  [in] PVOID Context,
  [in] BOOLEAN WriteToDevice
)
{...}
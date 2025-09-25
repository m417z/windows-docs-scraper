NDIS_PROCESS_SG_LIST NdisProcessSgList;

VOID NdisProcessSgList(
  [in] PDEVICE_OBJECT DeviceObject,
  [in] PVOID Reserved,
  [in] PSCATTER_GATHER_LIST ScatterGatherListBuffer,
  [in] PVOID Context
)
{...}
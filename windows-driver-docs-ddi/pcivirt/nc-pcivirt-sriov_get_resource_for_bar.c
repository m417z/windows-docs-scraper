SRIOV_GET_RESOURCE_FOR_BAR SriovGetResourceForBar;

NTSTATUS SriovGetResourceForBar(
  [in]  PVOID Context,
  [in]  USHORT VfIndex,
  [in]  USHORT BarIndex,
  [out] PCM_PARTIAL_RESOURCE_DESCRIPTOR Resource
)
{...}
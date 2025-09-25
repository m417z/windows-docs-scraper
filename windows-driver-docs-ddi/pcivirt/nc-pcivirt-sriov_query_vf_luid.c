SRIOV_QUERY_VF_LUID SriovQueryVfLuid;

NTSTATUS SriovQueryVfLuid(
  [in]  PVOID Context,
  [in]  USHORT VfIndex,
  [out] PLUID Luid
)
{...}
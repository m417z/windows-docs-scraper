SRIOV_QUERY_LUID_VF SriovQueryLuidVf;

NTSTATUS SriovQueryLuidVf(
  [in]  PVOID Context,
  [in]  LUID Luid,
  [out] PUSHORT VfIndex
)
{...}
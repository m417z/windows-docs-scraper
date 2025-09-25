SRIOV_QUERY_PROBED_BARS_2 SriovQueryProbedBars2;

NTSTATUS SriovQueryProbedBars2(
  [in]  PVOID Context,
  [in]  USHORT VfIndex,
  [out] PULONG BaseRegisterValues
)
{...}
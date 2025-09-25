SRIOV_GET_MMIO_REQUIREMENTS SriovGetMmioRequirements;

NTSTATUS SriovGetMmioRequirements(
  [in]  PVOID Context,
  [in]  USHORT VfIndex,
  [in]  ULONG BlockId,
  [out] PVOID Buffer,
  [in]  ULONG Length
)
{...}
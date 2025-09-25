SRIOV_READ_BLOCK SriovReadBlock;

NTSTATUS SriovReadBlock(
  [in]  PVOID Context,
  [in]  USHORT VfIndex,
  [in]  ULONG BlockId,
  [out] PVOID Buffer,
  [in]  ULONG Length
)
{...}
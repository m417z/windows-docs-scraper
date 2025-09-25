SRIOV_WRITE_BLOCK SriovWriteBlock;

NTSTATUS SriovWriteBlock(
  [in] PVOID Context,
  [in] USHORT VfIndex,
  [in] ULONG BlockId,
  [in] PVOID Buffer,
       ULONG Length
)
{...}
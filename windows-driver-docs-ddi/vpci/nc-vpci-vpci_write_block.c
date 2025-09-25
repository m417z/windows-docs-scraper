VPCI_WRITE_BLOCK VpciWriteBlock;

NTSTATUS VpciWriteBlock(
  PVOID Context,
  ULONG BlockId,
  PVOID Buffer,
  ULONG Length
)
{...}
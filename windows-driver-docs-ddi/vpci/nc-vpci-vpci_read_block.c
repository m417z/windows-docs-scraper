VPCI_READ_BLOCK VpciReadBlock;

NTSTATUS VpciReadBlock(
  PVOID Context,
  ULONG BlockId,
  PVOID Buffer,
  ULONG Length
)
{...}
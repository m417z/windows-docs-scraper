SRIOV_WRITE_CONFIG SriovWriteConfig;

NTSTATUS SriovWriteConfig(
  [in] PVOID Context,
  [in] const VOID *Data,
  [in] USHORT VfIndex,
  [in] ULONG Offset,
  [in] ULONG Length
)
{...}